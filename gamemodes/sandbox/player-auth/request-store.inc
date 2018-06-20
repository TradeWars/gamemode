// We're using BigETI's map plugin to simplify the process of knowing which
// player ID triggered which request.
static Map:SaveRequestToPlayerID;

accountStore(playerid) {
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
        storeClient,      // use the jsonstore client
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
