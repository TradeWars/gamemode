// player-spawn controls the spawn flow after invoking authentication.

// Internal packages
#include <class-selection>
#include <player-auth>

// y_hooks - this has to be last to generate new function names
#include <YSI\y_hooks>


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

hook OnPlayerLogin(playerid, bool:newPlayer) {
    spawnReadyPlayer(playerid, newPlayer);
}

spawnReadyPlayer(playerid, bool:newPlayer) {
    new
        Float:x,
        Float:y,
        Float:z,
        Float:a;

    if(newPlayer) {
        // TODO: random spawns
        x = DEFAULT_POS_X;
        y = DEFAULT_POS_Y;
        z = DEFAULT_POS_Z;
    } else {
        GetPlayerSpawnPosition(playerid, x, y, z, a);
    }

    dbg("player", "player logged in",
        _i("playerid", playerid),
        _f("x", x),
        _f("y", y),
        _f("z", z)
    );

    TogglePlayerSpectating(playerid, false);
    TogglePlayerControllable(playerid, true);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, a);
    SetCameraBehindPlayer(playerid);

    CallLocalFunction("OnPlayerSpawned", "d", playerid);
}

hook OnPlayerDisconnect(playerid, reason) {
    dbg("player", "player disconnect", _i("playerid", playerid));
    StorePlayerAccount(playerid);
}
