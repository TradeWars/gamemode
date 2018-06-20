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
    if(!IsValidRequestsClient(client)) {
        fatal("failed to create requests client");
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadAccount(playerid) {
    new path[8 + MAX_PLAYER_NAME];
    GetPlayerName(playerid, path, MAX_PLAYER_NAME);
    strins(path, "/users/", 0);

    dbg("player", "loading account",
        _i("playerid", playerid),
        _s("path", path));

    new Request:id = RequestJSON(
        client,          // use the jsonstore client
        path,            // use the player's name as the URL path
        HTTP_METHOD_GET, // use the HTTP GET method
        "onLoadData"     // call onLoadData when the response arrives
    );
    if(!IsValidRequest(id)) {
        err("failed to create request",
            _i("return", _:id));
        return;
    }

    // map the request ID to the player ID
    MAP_insert_val_val(LoadRequestToPlayerID, _:id, playerid);
}

forward onLoadData(Request:id, E_HTTP_STATUS:status, Node:node);
public onLoadData(Request:id, E_HTTP_STATUS:status, Node:node) {
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
    JsonGetBool(node, "ok", ok);
    if(!ok) {
        err("failed to get account, status not ok");
    }

    new Node:result = Node:-1; // invalid by default
    if(JsonGetObject(node, "result", result) != 0) {
        err("failed to get result from payload");
    }

    new bool:exists;
    if(JsonNodeType(result) != JSON_NODE_OBJECT) {
        dbg("player", "account does not exist", _i("playerid", playerid));
        exists = false;
    } else {
        dbg("player", "account exists", _i("playerid", playerid), _i("result", _:result));
        exists = true;
    }

    CallLocalFunction("OnAccountLoaded", "ddd", playerid, exists, _:result);

    return;
}

StoreAccount(playerid) {
    new path[8 + MAX_PLAYER_NAME];
    GetPlayerName(playerid, path, MAX_PLAYER_NAME);
    strins(path, "/users/", 0);

    new Node:object = JsonObject();
    JsonToggleGC(object, false);
    CallLocalFunction("OnAccountStore", "dd", playerid, _:object);
    JsonToggleGC(object, true);

    dbg("player", "storing account",
        _i("playerid", playerid),
        _s("path", path));

    new Request:id = RequestJSON(
        client,           // use the jsonstore client
        path,             // use the player's name as the URL path
        HTTP_METHOD_POST, // use the HTTP POST method
        "onSaveData",     // call onSaveData when the request has finished
        object
    );
    if(!IsValidRequest(id)) {
        err("failed to create request",
            _i("return", _:id));
        return;
    }

    // Same map strategy as with the loading data process
    MAP_insert_val_val(SaveRequestToPlayerID, _:id, playerid);
}

forward onSaveData(Request:id, E_HTTP_STATUS:status, Node:node);
public onSaveData(Request:id, E_HTTP_STATUS:status, Node:node) {
    new playerid = MAP_get_val_val(SaveRequestToPlayerID, _:id);
    MAP_remove_val(SaveRequestToPlayerID, _:id);

    if(status != HTTP_STATUS_CREATED) {
        err("failed to POST player data",
            _i("playerid", playerid),
            _i("status", _:status));
    } else {
        dbg("player", "player data stored",
            _i("playerid", playerid));
    }
}
