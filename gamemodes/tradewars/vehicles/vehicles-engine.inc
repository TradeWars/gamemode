// Handles the vehicles engine

// -
// External Packages
// -

#include <YSI\y_hooks>

// -
// Internal
// -

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER)
    {
        SetVehicleParameter(GetPlayerVehicleID(playerid), VEHICLE_PARAMETER_ENGINE, true);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(GetPlayerVehicleSeat(playerid) == 0)
    {
        SetVehicleParameter(vehicleid, VEHICLE_PARAMETER_ENGINE, false);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}