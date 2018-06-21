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

// RequestsClient stores the client information for making requests such as the
// endpoint and headers. Though in this example, we are no using any headers.
new RequestsClient:storeClient;

// BCRYPT_COST is used in bcrypt calls as the work factor for encryption.
new const BCRYPT_COST = 12;


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
    if(LoggedIn[playerid]) {
        accountStore(playerid);
    }
}


// -
// Internal
// -

#include "request-load"
#include "request-store"
#include "dialog-register"
#include "dialog-login"
#include <YSI\y_hooks>

static PasswordHash[MAX_PLAYERS][BCRYPT_HASH_LENGTH];
static bool:LoggedIn[MAX_PLAYERS];

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
        JsonGetString(node, "pass", PasswordHash[playerid], BCRYPT_HASH_LENGTH);
        promptLogin(playerid, PasswordHash[playerid]);
    } else {
        dbg("player", "new account required", _i("playerid", playerid));
        promptRegister(playerid);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnAccountStore(playerid, Node:node) {
    JsonSetString(node, "pass", PasswordHash[playerid], BCRYPT_HASH_LENGTH);
}

onLoggedIn(playerid) {
    bcrypt_get_hash(PasswordHash[playerid]);
    accountStore(playerid);
    signalReady(playerid, true);
}

// signalReady is called when the player has either successfully registered or
// logged in. This emits the OnPlayerLogin event.
signalReady(playerid, bool:newPlayer) {
    LoggedIn[playerid] = true;
    CallLocalFunction("OnPlayerLogin", "dd", playerid, newPlayer);
}
