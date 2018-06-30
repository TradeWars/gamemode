// Handles vehicle initilization and termination.

// -
// Declarations
// -

enum E_VEHICLE_DATA
{
    Float:VEHICLE_HEALTH,
    Float:VEHICLE_SPAWN_X,
    Float:VEHICLE_SPAWN_Y,
    Float:VEHICLE_SPAWN_Z,
    Float:VEHICLE_SPAWN_R
}

new vehicleData[MAX_VEHICLES][E_VEHICLE_DATA];

// -
// API
// -

// OnVehicleCreated is called when a vehicle has been succsesfully initialized
// using the CreateVehicle, AddStaticVehicle or AddStaticVehicleEx function.
forward OnVehicleCreated(vehicleid);

// OnVehicleTerminated is called when a vehicle has been succsesfully destroyed
// using the DestroyVehicle function.
forward OnVehicleTerminated(vehicle);

stock CreateVehicleHook(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren=0)
{
    new vehicleid = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
    registerVehicleData(vehicleid, x, y, z, rotation);

    return vehicleid;
}
#if defined _ALS_CreateVehicle
    #undef CreateVehicle
#else
    #define _ALS_CreateVehicle
#endif
#define CreateVehicle CreateVehicleHook

stock AddStaticVehicleHook(modelid, Float:x, Float:y, Float:z, Float:rotation, color1, color2)
{
    new vehicleid = AddStaticVehicle(modelid, x, y, z, rotation, color1, color2);
    registerVehicleData(vehicleid, x, y, z, rotation);

    return vehicleid;
}
#if defined _ALS_AddStaticVehicle
    #undef AddStaticVehicle
#else
    #define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle AddStaticVehicleHook

stock AddStaticVehicleExHook(modelid, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren=0)
{
    new vehicleid = AddStaticVehicleEx(modelid, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
    registerVehicleData(vehicleid, x, y, z, rotation);

    return vehicleid;
}
#if defined _ALS_AddStaticVehicleEx
    #undef AddStaticVehicleEx
#else
    #define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx AddStaticVehicleExHook

stock DestroyVehicleEx(vehicleid)
{
    new returnValue = DestroyVehicle(vehicleid);

    if(returnValue)
    {
        CallLocalFunction("OnVehicleTerminated", "i", vehicleid);
    }

    return returnValue;
}
#if defined _ALS_DestroyVehicle
    #undef DestroyVehicle
#else
    #define _ALS_DestroyVehicle
#endif
#define DestroyVehicle DestroyVehicleEx

// -
// Internal
// -

#include "vehicles-spawn"
#include "vehicles-utils"
#include "vehicles-engine"
//#include "vehicles-lock"

registerVehicleData(vehicleid, Float:x, Float:y, Float:z, Float:rotation)
{
    if(vehicleid != INVALID_VEHICLE_ID)
    {
        vehicleData[vehicleid][VEHICLE_SPAWN_X] = x;
        vehicleData[vehicleid][VEHICLE_SPAWN_Y] = y;
        vehicleData[vehicleid][VEHICLE_SPAWN_Z] = z;
        vehicleData[vehicleid][VEHICLE_SPAWN_R] = rotation;
        
        // Set all vehicle parameters to false by default in order
        // to prevent GetVehicleParameter from returning -1.
        // Due to this, the engine must be handled by the script.
        SetVehicleParamsEx(vehicleid, 0, 0, 0, 0, 0, 0, 0);

        SetVehicleNumberPlate(vehicleid, GenerateLicensePlateNumber());

        dbg("vehicle", "vehicle created", _i("vehicleid", vehicleid));
        CallLocalFunction("OnVehicleCreated", "i", vehicleid);
    }
    else
    {
        dbg("vehicle", "vehicle NOT created (vehicle limit reached or invalid vehicle model ID passed)");
    }
}
