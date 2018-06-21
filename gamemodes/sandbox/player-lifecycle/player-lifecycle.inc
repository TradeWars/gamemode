// player-spawn controls the spawn flow after invoking authentication.

// Internal packages
#include <class-selection>
#include <player-auth>


// -
// API
// -

// OnPlayerSpawned is called when the player has spawned after logging in or
// registering.
// Do not use the native `OnPlayerSpawn` event, use this instead.
forward OnPlayerSpawned(playerid);


// -
// Internal
// -

#include "spawn"

// y_hooks - this has to be last to generate new function names
#include <YSI\y_hooks>

static enum E_SPAWN {
    Float:E_SPAWN_X,
    Float:E_SPAWN_Y,
    Float:E_SPAWN_Z,
    Float:E_SPAWN_A,
}
static Spawn[MAX_PLAYERS][E_SPAWN];

hook OnPlayerReady(playerid) {
    dbg("player", "player ready", _i("playerid", playerid));

    SetPlayerCameraPos(playerid, 50.0, 50.0, 50.0);
    SetPlayerCameraLookAt(playerid, 0.0, 0.0, 0.0);

    // authentication can be disabled by building with NO_AUTH=1
    #if !defined NO_AUTH
        LoadPlayerAccount(playerid);
    #else
        #warning No authentication in player connect event
        spawnReadyPlayer(playerid, true);
    #endif

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// Load and Store

hook OnAccountLoaded(playerid, bool:exists, Node:node) {
    dbg("player", "account loaded", _i("playerid", playerid));

    if(exists) {
        new Node:spawn;
        new ret = JsonGetObject(node, "spawn", spawn);
        if(ret) {
            err("failed to read spawn field",
                _i("ret", ret));
        }
        JsonGetFloat(spawn, "posx", Spawn[playerid][E_SPAWN_X]);
        JsonGetFloat(spawn, "posy", Spawn[playerid][E_SPAWN_Y]);
        JsonGetFloat(spawn, "posz", Spawn[playerid][E_SPAWN_Z]);
        JsonGetFloat(spawn, "posa", Spawn[playerid][E_SPAWN_A]);
    } else {
        Spawn[playerid][E_SPAWN_X] = DEFAULT_POS_X;
        Spawn[playerid][E_SPAWN_Y] = DEFAULT_POS_Y;
        Spawn[playerid][E_SPAWN_Z] = DEFAULT_POS_Z;
        Spawn[playerid][E_SPAWN_A] = 0.0;
    }
}

hook OnAccountStore(playerid, Node:node) {
    dbg("player", "account storing", _i("playerid", playerid));

    GetPlayerPos(
        playerid,
        Spawn[playerid][E_SPAWN_X],
        Spawn[playerid][E_SPAWN_Y],
        Spawn[playerid][E_SPAWN_Z]
    );
    GetPlayerFacingAngle(playerid, Spawn[playerid][E_SPAWN_A]);

    JsonSetObject(node, "spawn", JsonObject(
        "posx", JsonFloat(Spawn[playerid][E_SPAWN_X]),
        "posy", JsonFloat(Spawn[playerid][E_SPAWN_Y]),
        "posz", JsonFloat(Spawn[playerid][E_SPAWN_Z]),
        "posa", JsonFloat(Spawn[playerid][E_SPAWN_A])
    ));
}

hook OnPlayerLogin(playerid, bool:newPlayer) {
    spawnReadyPlayer(playerid, newPlayer);
}

spawnReadyPlayer(playerid, bool:newPlayer) {
    if(newPlayer) {
        getSpawnPosition(
            Spawn[playerid][E_SPAWN_X],
            Spawn[playerid][E_SPAWN_Y],
            Spawn[playerid][E_SPAWN_Z],
            Spawn[playerid][E_SPAWN_A]
        );
    }

    dbg("player", "player logged in",
        _i("playerid", playerid),
        _i("newPlayer", newPlayer),
        _f("x", Spawn[playerid][E_SPAWN_X]),
        _f("y", Spawn[playerid][E_SPAWN_Y]),
        _f("z", Spawn[playerid][E_SPAWN_Z])
    );

    TogglePlayerSpectating(playerid, false);
    TogglePlayerControllable(playerid, true);
    SetPlayerPos(playerid, Spawn[playerid][E_SPAWN_X], Spawn[playerid][E_SPAWN_Y], Spawn[playerid][E_SPAWN_Z]);
    SetPlayerFacingAngle(playerid, Spawn[playerid][E_SPAWN_A]);
    SetCameraBehindPlayer(playerid);

    CallLocalFunction("OnPlayerSpawned", "d", playerid);
}

hook OnPlayerDisconnect(playerid, reason) {
    dbg("player", "player disconnect", _i("playerid", playerid));
    StorePlayerAccount(playerid);
}
