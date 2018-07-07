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
#include <ssc>
#include <errors>


// -
// Declarations
// -

// BCRYPT_COST is used in bcrypt calls as the work factor for encryption.
new const BCRYPT_COST = 12;

const MAX_OBJECT_ID_LEN = 25;

static PlayerObjectID[MAX_PLAYERS][MAX_OBJECT_ID_LEN];
static PasswordHash[MAX_PLAYERS][BCRYPT_HASH_LENGTH];
static bool:LoggedIn[MAX_PLAYERS];

// -
// API
// -

// OnAccountLoaded is called when the player's account data has been loaded or
// confirmed to not exist, which is reflected by `bool:exists`.
forward OnAccountLoaded(playerid, bool:exists, Node:node);

// OnAccountStore is called before an account is stored. This is where modules
// should append data to `node` using the `JsonSet` functions.
forward OnAccountStore(playerid, Node:node);

// OnPlayerLogin is called when a player successfully logs into the server.
// `newPlayer` indicates whether or not the player has just registered.
forward OnPlayerLogin(playerid, bool:newPlayer);

// IsPlayerLoggedIn returns true if the player is logged in.
stock bool:IsPlayerLoggedIn(playerid) {
    if(!IsPlayerConnected(playerid)) {
        return false;
    }
    return LoggedIn[playerid];
}

// LoadPlayerAccount is called to initiate the account load process. This
// function will trigger HTTP calls to get player data, it will display dialogs
// to the player and eventually, once the process has completed, the event
// `OnPlayerLogin` is emitted on success. On failure, the player is kicked.
stock Error:LoadPlayerAccount(playerid) {
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, MAX_PLAYER_NAME);
    return SSC_PlayerGetByName(storeClient, playerid, name);
}

// StorePlayerAccount can be called to trigger the storage request to run. This
// will call `OnAccountStore` so other packages can hook this and contribute
// data to the player's account JSON object.
stock Error:StorePlayerAccount(playerid) {
    if(!LoggedIn[playerid]) {
        return Error(1, "player not logged in");
    }

    new Node:object = JsonObject(
        "_id", JsonString(PlayerObjectID[playerid])
    );

    JsonToggleGC(object, false);
    CallLocalFunction("OnAccountStore", "dd", playerid, _:object);
    JsonToggleGC(object, true);

    return SSC_PlayerUpdate(storeClient, playerid, object);
}


// -
// Internal
// -

#include "dialog-register"
#include "dialog-login"
#include <YSI\y_hooks>

hook OnSSCPlayerGet(playerid, bool:success, message[], Error:error, Node:result) {
    if(IsError(error)) {
        PrintErrors();
        Handled();
    }

    if(success) {
        new Node:account;
        new ret = JsonGetObject(result, "account", account);
        if(ret) {
            err("failed to read account field",
                _i("ret", ret));
        }

        if(JsonGetString(account, "_id", PlayerObjectID[playerid], MAX_OBJECT_ID_LEN)) {
            err("failed to read account._id field");
        }

        if(JsonGetString(account, "pass", PasswordHash[playerid], BCRYPT_HASH_LENGTH)) {
            err("failed to read account.pass field");
        }

        dbg("player", "existing account loaded", _i("playerid", playerid));
        promptLogin(playerid, PasswordHash[playerid]);
    } else {
        dbg("player", "new account required", _i("playerid", playerid));
        promptRegister(playerid);
    }

    CallLocalFunction("OnAccountLoaded", "ddd", playerid, success, _:result);
}

hook OnSSCPlayerUpdate(playerid, bool:success, message[], Error:error, Node:result) {
    if(IsError(error)) {
        err("failed to update player data",
            _E(error));
        Handled();
    }

    if(!success) {
        err("updatePlayer failed",
            _s("message", message));
    }
}

hook OnSSCPlayerCreate(playerid, bool:success, message[], Error:error, Node:result) {
    if(IsError(error)) {
        err("failed to update player data",
            _E(error));
        Handled();
    }

    if(!success) {
        err("updatePlayer failed",
            _s("message", message));
    }

    new ret = JsonGetNodeString(result, PlayerObjectID[playerid], MAX_OBJECT_ID_LEN);
    if(ret) {
        err("failed to get result as string",
            _i("ret", ret));
    }
}

hook OnAccountStore(playerid, Node:node) {
    new
        name[MAX_PLAYER_NAME],
        ipv4[16],
        hash[41];

    GetPlayerName(playerid, name, MAX_PLAYER_NAME);
    GetPlayerIp(playerid, ipv4, sizeof ipv4);
    gpci(playerid, hash, sizeof hash);

    JsonSetObject(node, "account", JsonObject(
        "name", JsonString(name),
        "pass", JsonString(PasswordHash[playerid]),
        "ipv4", JsonString(ipv4),
        "gpci", JsonString(hash)
    ));
}

onRegistered(playerid) {
    bcrypt_get_hash(PasswordHash[playerid]);

    new Node:object = JsonObject();

    JsonToggleGC(object, false);
    CallLocalFunction("OnAccountStore", "dd", playerid, _:object);
    JsonToggleGC(object, true);

    new Error:e = SSC_PlayerCreate(storeClient, playerid, object);
    if(IsError(e)) {
        err("failed to send playerCreate request");
        return;
    }

    signalReady(playerid, true);
}

onLoggedIn(playerid) {
    signalReady(playerid, true);
}

// signalReady is called when the player has either successfully registered or
// logged in. This emits the OnPlayerLogin event.
signalReady(playerid, bool:newPlayer) {
    dbg("player", "player authenticated successfully", _i("playerid", playerid));

    LoggedIn[playerid] = true;
    CallLocalFunction("OnPlayerLogin", "dd", playerid, newPlayer);
}
