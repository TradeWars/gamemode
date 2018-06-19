// Contains account load and creation code.

#include <YSI\y_hooks>



// OnAccountLoaded is called when a player has completed the login flow and has
// either an existing account or needs to register a new one.
forward OnAccountLoaded(playerid, bool:exists, Node:node);

// OnAccountStore is called before an account is stored. This is where modules
// should append data to `node` using JsonAppend.
forward OnAccountStore(playerid, Node:node);

// RequestsClient stores the client information for making requests such as the
// endpoint and headers. Though in this example, we are no using any headers.
static RequestsClient:client;

// We're using BigETI's map plugin to simplify the process of knowing which
// player ID triggered which request.
static Map:LoadRequestToPlayerID;
static Map:SaveRequestToPlayerID;

hook OnScriptInit() {
    new endpoint[128];
    GetSettingString("settings.ini", "endpoint", "", endpoint);
    if(endpoint[0] == EOS) {
        fatal("Could not load 'endpoint' from settings.ini");
    }

    // Create the requests client with the endpoint.
    client = RequestsClient(endpoint);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadAccount(playerid) {
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, MAX_PLAYER_NAME);

    // This is our first request - this sends a GET request to jsonstore.io and
    // uses the player's name as the path. The full URL would look something
    // like: `https://jsonstore.io/<key>/Southclaws` for my username.
    new Request:id = RequestJSON(
        client,          // use the jsonstore client
        name,            // use the player's name as the URL path
        HTTP_METHOD_GET, // use the HTTP GET method
        "OnLoadData"     // call OnLoadData when the response arrives
    );

    // map the request ID to the player ID
    MAP_insert_val_val(LoadRequestToPlayerID, _:id, playerid);
}

forward OnLoadData(Request:id, E_HTTP_STATUS:status, Node:node);
public OnLoadData(Request:id, E_HTTP_STATUS:status, Node:node) {
    // get the player's ID from the request ID that was stored in
    // OnPlayerConnect
    new playerid = MAP_get_val_val(LoadRequestToPlayerID, _:id);
    MAP_remove_val(LoadRequestToPlayerID, _:id);

    // jsonstore.io always uses OK status, even if the data is missing
    if(status != HTTP_STATUS_OK) {
        SendClientMessage(playerid, -1, "An unknown error occurred!");
        err("response status was not OK",
            _i("playerid", playerid),
            _i("status", _:status));
    }

    // jsonstore.io always responds with an object with two fields:
    // "ok"
    // "result"
    // ok is a bool that indicates if the document exists, so check we check it:
    new bool:ok;
    new Node:result = Node:-1; // invalid by default
    JsonGetBool(node, "ok", ok);
    if(ok) {
        JsonGetObject(node, "result", result);
    }

    CallLocalFunction("OnAccountLoaded", "ddd", playerid, ok, _:result);

    return;
}

StoreAccount(playerid) {
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, MAX_PLAYER_NAME);

    new Node:object = JsonObject();
    CallLocalFunction("OnAccountStore", "dd", playerid, _:object);

    // Sends a POST request to jsonstore.io with a JSON object built inline
    new Request:id = RequestJSON(
        client,           // use the jsonstore client
        name,             // use the player's name as the URL path
        HTTP_METHOD_POST, // use the HTTP POST method
        "OnSaveData",     // call OnSaveData when the request has finished
        object
    );

    // Same map strategy as with the loading data process
    MAP_insert_val_val(SaveRequestToPlayerID, _:id, playerid);
}

forward OnSaveData(Request:id, E_HTTP_STATUS:status, Node:node);
public OnSaveData(Request:id, E_HTTP_STATUS:status, Node:node) {
    new playerid = MAP_get_val_val(SaveRequestToPlayerID, _:id);
    MAP_remove_val(SaveRequestToPlayerID, _:id);

    if(status != HTTP_STATUS_CREATED) {
        err("failed to POST player data",
            _i("playerid", playerid),
            _i("status", _:status));
    } else {
        log("player data stored",
            _i("playerid", playerid));
    }
}
