promptRegister(playerid) {
    dbg("player", "prompting registration", _i("playerid", playerid));
    Dialog_Open(
        playerid,
        "onRegisterResponse",
        DIALOG_STYLE_INPUT,
        "Register",
        "Register for a new account",
        "Confirm",
        "Leave"
    );
}

Dialog:onRegisterResponse(playerid, response, item, input[]) {
    if(!response) {
        dbg("player", "player left at registration", _i("playerid", playerid));
        Kick(playerid);
        return;
    }

    if(strlen(input) < 10) {
        promptRegister(playerid);
        return;
    }

    dbg("player", "hashing player password",
        _i("playerid", playerid));

    new buf[WHIRLPOOL_LEN];
    WP_Hash(buf, WHIRLPOOL_LEN, input);
    onRegistered(playerid, buf);

    return;
}
