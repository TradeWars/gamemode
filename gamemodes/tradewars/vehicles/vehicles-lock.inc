// Handles the vehicles lock

// -
// External Packages
// -

#include <YSI\y_timers>
#include <YSI\y_hooks>

// -
// Internal
// -

// TODO Also add a command to unlock/lock for **special** people

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
        // I think this key would be great for unlocking/locking vehicles.
        // H is used by the horn, 2 are used for vehicle special actions
        // (Plane wheels). And I think N would be great to quickly open
        // up the inventory dialog.
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

lockUnlockVehicle(playerid, vehicleid)
{
    new newState = ToggleVehicleParameter(vehicleid, VEHICLE_PARAMETER_DOORS);

    flashVehicleHeadLights(vehicleid);
    PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
    GameTextForPlayer(playerid, (newState) ? ("~n~~r~Locked") : ("~n~~g~Unlocked"), 2000, 4);
}

flashVehicleHeadLights(vehicleid)
{
    SetVehicleParameter(vehicleid, VEHICLE_PARAMETER_LIGHTS, true);
	defer flashVehicleHeadLightsTimer(vehicleid);
}

timer flashVehicleHeadLightsTimer[250](vehicleid)
{
    SetVehicleParameter(vehicleid, VEHICLE_PARAMETER_LIGHTS, false);
}
