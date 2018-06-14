// Contains connection flow and spawn code.

#include <YSI\y_hooks>


#define MAX_PASSWORD_LEN (128)


hook OnPlayerConnect(playerid) {
    log("player connect", _i("playerid", playerid));

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerReady(playerid) {
    log("player ready", _i("playerid", playerid));

    SetPlayerCameraPos(playerid, 50.0, 50.0, 50.0);
    SetPlayerCameraLookAt(playerid, 0.0, 0.0, 0.0);

    StartLoginFlow(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnLoginSuccess(playerid, bool:newPlayer) {
    new
        Float:x,
        Float:y,
        Float:z,
        Float:a;

    GetPlayerSpawn(playerid, x, y, z, a);
    TogglePlayerSpectating(playerid, false);
    TogglePlayerControllable(playerid, true);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, a);
    SetCameraBehindPlayer(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}
