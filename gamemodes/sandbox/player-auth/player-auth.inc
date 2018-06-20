// Handles authentication flow, provides success event for when authentication
// has completed.

// -
// External packages
// -

#include <settings>
#include <requests>
#include <map>
#include <easyDialog>
#include <bcrypt>


// -
// Declarations
// -

static enum E_PLAYER {
    E_PLAYER_PASS[BCRYPT_HASH_LENGTH],
    Float:E_PLAYER_SPAWN_X,
    Float:E_PLAYER_SPAWN_Y,
    Float:E_PLAYER_SPAWN_Z,
    Float:E_PLAYER_SPAWN_A,
    Float:E_PLAYER_HEALTH,
    Float:E_PLAYER_ARMOUR,
    E_PLAYER_CASH,
}


// RequestsClient stores the client information for making requests such as the
// endpoint and headers. Though in this example, we are no using any headers.
new RequestsClient:storeClient;

// BCRYPT_COST is used in bcrypt calls as the work factor for encryption.
new const BCRYPT_COST = 12;

static Data[MAX_PLAYERS][E_PLAYER];
static bool:LoggedIn[MAX_PLAYERS];


// -
// Internal modules
// -

#include "request-load"
#include "request-store"
#include "dialog-register"
#include "dialog-login"

// y_hooks - this has to be last to generate new function names
#include <YSI\y_hooks>


// -
// API
// -

// OnAccountLoaded is called when a player has completed the login flow and has
// either an existing account or needs to register a new one.
forward OnAccountLoaded(playerid, bool:exists, Node:node);

// OnAccountStore is called before an account is stored. This is where modules
// should append data to `node` using the `JsonSet` functions.
forward OnAccountStore(playerid, Node:node);

// OnPlayerLogin is called when a player successfully logs into the server.
// `newPlayer` indicates whether or not the player has just registered.
forward OnPlayerLogin(playerid, bool:newPlayer);

// LoadPlayerAccount is called to initiate the account load process. This
// function will trigger HTTP calls to get player data, it will display dialogs
// to the player and eventually, once the process has completed, the event
// `OnPlayerLogin` is emitted on success. On failure, the player is kicked.
stock LoadPlayerAccount(playerid) {
    accountLoad(playerid);
}

// StorePlayerAccount can be called to trigger the storage request to run. This
// will call `OnAccountStore` so other packages can hook this and contribute
// data to the player's account JSON object.
stock StorePlayerAccount(playerid) {
    accountStore(playerid);
}

// GetPlayerSpawnPosition returns the player's loaded spawn position. This
// should only ever really be called within `OnPlayerLogin`.
stock GetPlayerSpawnPosition(playerid, &Float:x, &Float:y, &Float:z, &Float:a) {
    if(!LoggedIn[playerid]) {
        return 1;
    }

    x = Data[playerid][E_PLAYER_SPAWN_X];
    y = Data[playerid][E_PLAYER_SPAWN_Y];
    z = Data[playerid][E_PLAYER_SPAWN_Z];
    a = Data[playerid][E_PLAYER_SPAWN_A];

    return 0;
}


// -
// Internal
// -

hook OnPlayerConnect(playerid) {
    dbg("player", "player connect", _i("playerid", playerid));

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnScriptInit() {
    new endpoint[128];
    GetSettingString("settings.ini", "endpoint", "", endpoint);
    if(endpoint[0] == EOS) {
        fatal("Could not load 'endpoint' from settings.ini");
    }

    // Create the requests client with the endpoint.
    storeClient = RequestsClient(endpoint);
    if(!IsValidRequestsClient(storeClient)) {
        fatal("failed to create requests client");
    }

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
        promptLogin(playerid, Data[playerid][E_PLAYER_PASS]);
    } else {
        dbg("player", "new account required", _i("playerid", playerid));
        promptRegister(playerid);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

onLoggedIn(playerid) {
    bcrypt_get_hash(Data[playerid][E_PLAYER_PASS]);
    accountStore(playerid);
    signalReady(playerid, true);
}

// signalReady is called when the player has either successfully registered or
// logged in. This emits the OnPlayerLogin event.
signalReady(playerid, bool:newPlayer) {
    LoggedIn[playerid] = true;
    CallLocalFunction("OnPlayerLogin", "dd", playerid, newPlayer);
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
