// Spawns vehicles around the map on gamemode initialization.

// -
// External packages
// -

#include <fsutil>
#include <sscanf2>
#include <settings>

// y_hooks - this has to be last to generate new function names
#include <YSI\y_hooks>

// -
// Internal
// -

hook OnGameModeInit()
{
    new vehicleLocationsPath[128];
    GetSettingString("settings.ini", "vehicle_locations", "scriptfiles/vehicles/", vehicleLocationsPath);
    loadVehiclesFromDirectory(vehicleLocationsPath);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

loadVehiclesFromDirectory(directory[])
{
    new
        Directory:directoryHandle = OpenDir(directory),
        itemName[256],
        ENTRY_TYPE:itemType;

    if(directoryHandle == Directory:-1)
    {
        err("failed to read from directory", _s("directory", directory));
        return 0;
    }

    while(DirNext(directoryHandle, itemType, itemName))
    {
        if(itemType == E_DIRECTORY)
        {
            loadVehiclesFromDirectory(itemName);
        }
        else if(itemType == E_REGULAR)
        {
            // start from index 12 to trim "scriptfiles/"
            // TODO: rewrite this when fsutil gets full path IO functions
            loadVehiclesFromFile(itemName[12]);
        }
    }

    CloseDir(directoryHandle);
    return 1;
}

loadVehiclesFromFile(file[])
{
    new File:fileHandle = fopen(file);

    if(!fexist(file))
    {
        err("file does not exist", _s("directory", file));
        return 0;
    }

    new line[256],
        vModel,
        Float:vPosX,
        Float:vPosY,
        Float:vPosZ,
        Float:vRotation,
        vColor1,
        vColor2;

    while(fread(fileHandle, line, sizeof(line)))
    {
        if(!sscanf(line, "p<,>iffffip<;>i{s[128]}", vModel, vPosX, vPosY, vPosZ, vRotation, vColor1, vColor2))
        {
            // Create static vehicle if the model of the vehicle is a train
            // (Trains can only be created statically).
            if(vModel == 537 || vModel == 538)
            {
                AddStaticVehicle(vModel, vPosX, vPosY, vPosZ, vRotation, vColor1, vColor2);
            }
            else
            {
                CreateVehicle(vModel, vPosX, vPosY, vPosZ, vRotation, vColor1, vColor2, 60 * 10);
            }
        }
        else
        {
            continue;
        }
    }

    fclose(fileHandle);
    return 1;
}
