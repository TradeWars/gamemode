// Contains login code, calls a callback with load result

#include <YSI\y_hooks>


enum E_PLAYER_DATA {
    E_PLAYER_PASSWORD[MAX_PASSWORD_LEN],
    Float:E_PLAYER_SPAWN_X,
    Float:E_PLAYER_SPAWN_Y,
    Float:E_PLAYER_SPAWN_Z,
    Float:E_PLAYER_SPAWN_A,
    Float:E_PLAYER_HEALTH,
    Float:E_PLAYER_ARMOUR,
    E_PLAYER_CASH,
}

static Data[MAX_PLAYERS][E_PLAYER_DATA];

// OnAccountLoaded is called when a player has completed the login flow and has
// either an existing account or needs to register a new one.
forward OnAccountLoaded(playerid, Node:node);

// RequestsClient stores the client information for making requests such as the
// endpoint and headers. Though in this example, we are no using any headers.
static RequestsClient:client;

// We're using BigETI's map plugin to simplify the process of knowing which
// player ID triggered which request.
static Map:LoadRequestToPlayerID;

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

StartLoginFlow(playerid) {
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
    if(!ok) {
        // this is the equivalent of a "404 not found"

        SendClientMessage(playerid, -1, "Welcome to the server, first-timer!");
        // set the player's position to a sane default
        Data[playerid][E_PLAYER_SPAWN_X] = DEFAULT_POS_X;
        Data[playerid][E_PLAYER_SPAWN_Y] = DEFAULT_POS_Y;
        Data[playerid][E_PLAYER_SPAWN_Z] = DEFAULT_POS_Z;

        // return, nothing else to do
        return;
    } else {
        // now, the result exists so extract it as a JSON object
        JsonGetObject(node, "result", result);

        JsonGetFloat(node, "x", Data[playerid][E_PLAYER_SPAWN_X]);
        JsonGetFloat(node, "y", Data[playerid][E_PLAYER_SPAWN_Y]);
        JsonGetFloat(node, "z", Data[playerid][E_PLAYER_SPAWN_Z]);
        JsonGetFloat(node, "a", Data[playerid][E_PLAYER_SPAWN_A]);
        JsonGetFloat(node, "health", Data[playerid][E_PLAYER_HEALTH]);
        JsonGetFloat(node, "armour", Data[playerid][E_PLAYER_ARMOUR]);
        JsonGetInt(node, "cash", Data[playerid][E_PLAYER_CASH]);
    }

    return;
}


// -
// Interface
// -

stock GetPlayerSpawn(playerid, &Float:x, &Float:y, &Float:z, &Float:a) {
    if(IsPlayerConnected(playerid)) {
        return 1;
    }

    x = Data[playerid][E_PLAYER_SPAWN_X];
    y = Data[playerid][E_PLAYER_SPAWN_Y];
    z = Data[playerid][E_PLAYER_SPAWN_Z];
    a = Data[playerid][E_PLAYER_SPAWN_A];

    return 0;
}
