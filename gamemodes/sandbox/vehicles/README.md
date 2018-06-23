# Vehicles

This package handles vehicle initialization/termination, spawns vehicles around the
map and provides utility functions.

# API

## Events

## `OnVehicleCreated (vehicleid)`

This package emits the `OnVehicleCreated` event whenever a vehicle has been
succsesfully created using the CreateVehicle, AddStaticVehicle or
AddStaticVehicleEx functions.

## `OnVehicleTerminated (vehicleid)`

This package emits the `OnVehicleTerminated` event whenever a vehicle has been
succsesfully destroyed using the DestroyVehicle function.

Use `OnVehicleDeath` if you want to execute code when a vehicle is destroyed
(Either by an explosion or by becoming submerged in water).

## Functions

## `GetVehicleParameter (vehicleid, parameter)`

This function returns the state of an individual parameter, rather than
all parameters.

**This function returns :**
* **0/1** the state of the specified parameter
* **-1** if the parameter hasn't been set before
* **-2** if the parameter specified is invalid

## `SetVehicleParameter (vehicleid, parameter, value)`

This function sets the state of an individual parameter, rather than
setting the state of all parameters.

**This function returns :**
* **1** if it executed succsesfully
* **0** if it fails to execute (This means the vehicle does not exist)

## `ToggleVehicleParameter (vehicleid, parameter)`

This function toggles the state of the parameter specified. If the state was
previously 0, it would now be 1 and vice versa.

**This function returns :**
* The new state of the vehicle parameter specified. (0/1)

## `GenerateLicensePlateNumber ()`

This function returns a string containing a license plate "number". It is
constructed of 7 random numbers and characters.

## `GetPlayerNearbyVehicle (playerid, Float:range = 3.0)`

Returns the vehicleid of a nearby vehicle within range of the players position.

**This function returns :**
* The vehicleid of a nearby vehicle.
* **-1** if none were found.

# Global declarations

Vehicle parameters :
* VEHICLE_PARAMETER_ENGINE
* VEHICLE_PARAMETER_LIGHTS
* VEHICLE_PARAMETER_ALARM
* VEHICLE_PARAMETER_DOORS
* VEHICLE_PARAMETER_BONNET
* VEHICLE_PARAMETER_BOOT
* VEHICLE_PARAMETER_OBJECTIVE