// We're using BigETI's map plugin to simplify the process of knowing which
// player ID triggered which request.
static Map:LoadRequestToPlayerID;

accountLoad(playerid) {
    new
        path[128],
        name[MAX_PLAYER_NAME];

    GetPlayerName(playerid, path, MAX_PLAYER_NAME);
    format(path, sizeof path, "/store/playerGet?name=%s", name);

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

    new bool:success;
    new Node:result;
    new message[128];
    new Error:e = ParseStatus(node, success, result, message);
    if(IsError(e)) {
        err("failed to parse status",
            _s("message", message),
            _E(e));
        Handled();
    }

    if(status != HTTP_STATUS_OK) {
        SendClientMessage(playerid, -1, "An unknown error occurred!");
        err("response status was not OK",
            _i("playerid", playerid),
            _i("status", _:status));
    }

    CallLocalFunction("OnAccountLoaded", "ddd", playerid, success, _:result);

    return;
}
