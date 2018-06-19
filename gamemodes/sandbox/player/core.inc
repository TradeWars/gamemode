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
static const BCRYPT_COST = 12;

hook OnPlayerConnect(playerid) {
    log("player connect", _i("playerid", playerid));

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerReady(playerid) {
    log("player ready", _i("playerid", playerid));

    SetPlayerCameraPos(playerid, 50.0, 50.0, 50.0);
    SetPlayerCameraLookAt(playerid, 0.0, 0.0, 0.0);

    // LoadAccount requests data from the database and calls `OnAccountLoaded`
    // when it's available.
    LoadAccount(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnAccountLoaded(playerid, bool:exists, Node:node) {
    if(exists) {
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
        Kick(playerid);
        return;
    }

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
        spawnReadyPlayer(playerid);
    } else {
        // TODO: attempt counter for anti-bruteforce attack
        promptLogin(playerid);
    }
}

promptRegister(playerid) {
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
        Kick(playerid);
        return;
    }
    bcrypt_hash(input, BCRYPT_COST, "onPasswordHashed", "d", playerid);
}
forward onPasswordHashed(playerid);
public onPasswordHashed(playerid) {
    bcrypt_get_hash(Data[playerid][E_PLAYER_PASS]);
    StoreAccount(playerid);
}

hook OnAccountStore(playerid, Node:node) {
    // TODO: Waiting on pawn-requests update
    // JsonSetString(node, "pass", Data[playerid][E_PLAYER_PASS], BCRYPT_HASH_LENGTH);
    // JsonSetFloat(node, "x", Data[playerid][E_PLAYER_SPAWN_X]);
    // JsonSetFloat(node, "y", Data[playerid][E_PLAYER_SPAWN_Y]);
    // JsonSetFloat(node, "z", Data[playerid][E_PLAYER_SPAWN_Z]);
    // JsonSetFloat(node, "a", Data[playerid][E_PLAYER_SPAWN_A]);
    // JsonSetFloat(node, "health", Data[playerid][E_PLAYER_HEALTH]);
    // JsonSetFloat(node, "armour", Data[playerid][E_PLAYER_ARMOUR]);
    // JsonSetInt(node, "cash", Data[playerid][E_PLAYER_CASH]);
}

// spawnReadyPlayer is called after a player has successfully registered or
// logged in. When this is called, all player data is assumed ready for reading.
spawnReadyPlayer(playerid) {
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
    StoreAccount(playerid);
}
