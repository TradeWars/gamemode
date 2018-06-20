// We're using BigETI's map plugin to simplify the process of knowing which
// player ID triggered which request.
static Map:LoadRequestToPlayerID;


accountLoad(playerid) {
    new path[8 + MAX_PLAYER_NAME];
    GetPlayerName(playerid, path, MAX_PLAYER_NAME);
    strins(path, "/users/", 0);

    dbg("player", "loading account",
        _i("playerid", playerid),
        _s("path", path));

    new Request:id = RequestJSON(
        storeClient,     // use the jsonstore client
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
