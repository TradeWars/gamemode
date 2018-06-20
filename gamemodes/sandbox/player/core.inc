// Contains connection flow and spawn code.

#include <YSI\y_hooks>


static enum E_PLAYER_DATA {
    E_PLAYER_PASS[BCRYPT_HASH_LENGTH],
    Float:E_PLAYER_SPAWN_X,
    Float:E_PLAYER_SPAWN_Y,
    Float:E_PLAYER_SPAWN_Z,
    Float:E_PLAYER_SPAWN_A,
    Float:E_PLAYER_HEALTH,
    Float:E_PLAYER_ARMOUR,
    E_PLAYER_CASH,
}


static Data[MAX_PLAYERS][E_PLAYER_DATA];
static bool:LoggedIn[MAX_PLAYERS];
static const BCRYPT_COST = 12;

hook OnPlayerConnect(playerid) {
    dbg("player", "player connect", _i("playerid", playerid));

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerReady(playerid) {
    dbg("player", "player ready", _i("playerid", playerid));

    SetPlayerCameraPos(playerid, 50.0, 50.0, 50.0);
    SetPlayerCameraLookAt(playerid, 0.0, 0.0, 0.0);

    // LoadAccount requests data from the database and calls `OnAccountLoaded`
    // when it's available.
    LoadAccount(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnAccountLoaded(playerid, bool:exists, Node:node) {
    if(exists) {
        dbg("player", "existing account loaded", _i("playerid", playerid));
        JsonGetString(node, "pass", Data[playerid][E_PLAYER_PASS], BCRYPT_HASH_LENGTH);
        JsonGetFloat(node, "x", Data[playerid][E_PLAYER_SPAWN_X]);
        JsonGetFloat(node, "y", Data[playerid][E_PLAYER_SPAWN_Y]);
        JsonGetFloat(node, "z", Data[playerid][E_PLAYER_SPAWN_Z]);
        JsonGetFloat(node, "a", Data[playerid][E_PLAYER_SPAWN_A]);
        JsonGetFloat(node, "health", Data[playerid][E_PLAYER_HEALTH]);
        JsonGetFloat(node, "armour", Data[playerid][E_PLAYER_ARMOUR]);
        JsonGetInt(node, "cash", Data[playerid][E_PLAYER_CASH]);
        promptLogin(playerid);
    } else {
        dbg("player", "new account required", _i("playerid", playerid));
        Data[playerid][E_PLAYER_PASS][0] = EOS;
        Data[playerid][E_PLAYER_SPAWN_X] = DEFAULT_POS_X;
        Data[playerid][E_PLAYER_SPAWN_Y] = DEFAULT_POS_Y;
        Data[playerid][E_PLAYER_SPAWN_Z] = DEFAULT_POS_Z;
        Data[playerid][E_PLAYER_SPAWN_A] = 0.0;
        Data[playerid][E_PLAYER_HEALTH] = 100.0;
        Data[playerid][E_PLAYER_ARMOUR] = 0.0;
        Data[playerid][E_PLAYER_CASH] = 0;
        promptRegister(playerid);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

promptLogin(playerid) {
    dbg("player", "prompting login", _i("playerid", playerid));
    Dialog_Open(
        playerid,
        "onLoginResponse",
        DIALOG_STYLE_INPUT,
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

    dbg("player", "player requesting password check", _i("playerid", playerid));
    bcrypt_check(
        input,
        Data[playerid][E_PLAYER_PASS],
        "onPasswordChecked",
        "d",
        playerid
    );
}
forward onPasswordChecked(playerid);
public onPasswordChecked(playerid) {
    if(bcrypt_is_equal()) {
        dbg("player", "password check passed", _i("playerid", playerid));
        LoggedIn[playerid] = true;
        spawnReadyPlayer(playerid);
    } else {
        dbg("player", "password check failed", _i("playerid", playerid));
        // TODO: attempt counter for anti-bruteforce attack
        promptLogin(playerid);
    }
}

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
    bcrypt_get_hash(Data[playerid][E_PLAYER_PASS]);
    LoggedIn[playerid] = true;
    StoreAccount(playerid);
    spawnReadyPlayer(playerid);
}

hook OnAccountStore(playerid, Node:node) {
    dbg("player", "account store request", _i("playerid", playerid));

    GetPlayerPos(
        playerid,
        Data[playerid][E_PLAYER_SPAWN_X],
        Data[playerid][E_PLAYER_SPAWN_Y],
        Data[playerid][E_PLAYER_SPAWN_Z]
    );
    GetPlayerFacingAngle(playerid, Data[playerid][E_PLAYER_SPAWN_A]);
    GetPlayerHealth(playerid, Data[playerid][E_PLAYER_HEALTH]);
    GetPlayerArmour(playerid, Data[playerid][E_PLAYER_ARMOUR]);
    Data[playerid][E_PLAYER_CASH] = GetPlayerMoney(playerid);

    JsonSetString(node, "pass", Data[playerid][E_PLAYER_PASS], BCRYPT_HASH_LENGTH);
    JsonSetFloat(node, "x", Data[playerid][E_PLAYER_SPAWN_X]);
    JsonSetFloat(node, "y", Data[playerid][E_PLAYER_SPAWN_Y]);
    JsonSetFloat(node, "z", Data[playerid][E_PLAYER_SPAWN_Z]);
    JsonSetFloat(node, "a", Data[playerid][E_PLAYER_SPAWN_A]);
    JsonSetFloat(node, "health", Data[playerid][E_PLAYER_HEALTH]);
    JsonSetFloat(node, "armour", Data[playerid][E_PLAYER_ARMOUR]);
    JsonSetInt(node, "cash", Data[playerid][E_PLAYER_CASH]);
}

// spawnReadyPlayer is called after a player has successfully registered or
// logged in. When this is called, all player data is assumed ready for reading.
spawnReadyPlayer(playerid) {
    dbg("player", "spawning ready player",
        _i("playerid", playerid),
        _f("x", Data[playerid][E_PLAYER_SPAWN_X]),
        _f("y", Data[playerid][E_PLAYER_SPAWN_Y]),
        _f("z", Data[playerid][E_PLAYER_SPAWN_Z])
    );

    TogglePlayerSpectating(playerid, false);
    TogglePlayerControllable(playerid, true);
    SetPlayerPos(playerid,
        Data[playerid][E_PLAYER_SPAWN_X],
        Data[playerid][E_PLAYER_SPAWN_Y],
        Data[playerid][E_PLAYER_SPAWN_Z]);
    SetPlayerFacingAngle(playerid, Data[playerid][E_PLAYER_SPAWN_A]);
    SetCameraBehindPlayer(playerid);
}

hook OnPlayerDisconnect(playerid, reason) {
    dbg("player", "player disconnect", _i("playerid", playerid));
    if(LoggedIn[playerid]) {
        StoreAccount(playerid);
    }
}
