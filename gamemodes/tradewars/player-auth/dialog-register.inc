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

    dbg("player", "player requesting password hash", _i("playerid", playerid));
    bcrypt_hash(input, BCRYPT_COST, "onPasswordHashed", "d", playerid);
}

forward onPasswordHashed(playerid);
public onPasswordHashed(playerid) {
    dbg("player", "password hash complete", _i("playerid", playerid));
    onRegistered(playerid);
}
