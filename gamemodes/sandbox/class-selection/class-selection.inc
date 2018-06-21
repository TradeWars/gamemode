// Class selection override


// -
// Declarations
// -

const DEFAULT_POS_X = 300.0;
const DEFAULT_POS_Y = 1800.0;
const DEFAULT_POS_Z = 18.0;


// -
// API
// -

// OnPlayerReady is called when a player is ready to be taken over by the script
// again and their class selection override flow has completed.
forward OnPlayerReady(playerid);


// -
// Internal
// -

#include <YSI\y_hooks>

static bool:connecting[MAX_PLAYERS];

hook OnPlayerConnect(playerid) {
	dbg("player", "player spawn assigned", _i("playerid", playerid));

	SetSpawnInfo(playerid, NO_TEAM, 101,
		DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_POS_Z,
		0.0, 0, 0, 0, 0, 0, 0);
	
	connecting[playerid] = true;

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerRequestClass(playerid, classid) {
	dbg("player", "player request class", _i("playerid", playerid));

	SetSpawnInfo(playerid, NO_TEAM, 101,
		DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_POS_Z,
		0.0, 0, 0, 0, 0, 0, 0);
	// the order of these functions is important
	TogglePlayerSpectating(playerid, true);
	SpawnPlayer(playerid);

	return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerSpawn(playerid) {
	if(connecting[playerid]) {
		dbg("player", "player performing first spawn", _i("playerid", playerid));
		// OnPlayerReady indicates the class-selection skip code has finished.
		CallLocalFunction("OnPlayerReady", "d", playerid);
		connecting[playerid] = false;
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}
