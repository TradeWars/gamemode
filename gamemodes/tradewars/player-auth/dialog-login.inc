// PasswordHash is to store the player's password hash that was loaded from the
// database. This is because the password hash is passed in via `promptLogin`
// so it does not need to be shared globally.
static PasswordHash[MAX_PLAYERS][WHIRLPOOL_LEN];

promptLogin(playerid, passwordHash[], len = sizeof passwordHash) {
    dbg("player", "prompting login", _i("playerid", playerid));

    strcat(PasswordHash[playerid], passwordHash, len);
    Dialog_Open(
        playerid,
        "onLoginResponse",
        DIALOG_STYLE_PASSWORD,
        "Login",
        "Login to your account",
        "Confirm",
        "Leave"
    );
}

Dialog:onLoginResponse(playerid, response, item, input[]) {
    if(!response) {
        dbg("player", "player left at login", _i("playerid", playerid));
        Kick(playerid);
        return;
    }

    new buf[WHIRLPOOL_LEN];
    WP_Hash(buf, WHIRLPOOL_LEN, input);
    if(strcmp(buf, PasswordHash[playerid])) {
        dbg("player", "password check failed",
            _i("playerid", playerid));

        // TODO: attempt counter for anti-bruteforce attack
        promptLogin(playerid, PasswordHash[playerid]);
    } else {
        dbg("player", "password check passed",
            _i("playerid", playerid));

        onLoggedIn(playerid);
    }
}
