// Spawns vehicles around the map on gamemode initialization.

// -
// External packages
// -

#include <filemanager>
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
    new dir:directoryHandle = dir_open(directory),
        itemName[40], itemType,
        path[256];

    if(!directoryHandle)
    {
        err("[loadVehiclesFromDirectory] Failed to read from directory!", _s("directory", directory));        
        return 0;
    }

    while(dir_list(directoryHandle, itemName, itemType))
    {
        if(itemType == FM_DIR && strcmp(itemName, "..") && strcmp(itemName, ".") && strcmp(itemName, "_"))
        {
            path[0] = EOS;
            format(path, sizeof(path), "%s/%s/", directory, itemName);
            loadVehiclesFromDirectory(path);
        }
        else if(itemType == FM_FILE)
        {
            path[0] = EOS;
            format(path, sizeof(path), "%s/%s", directory, itemName);
            loadVehiclesFromFile(path);
        }
    }
            
    dir_close(directoryHandle);
    return 1;
}

loadVehiclesFromFile(file[])
{
    new File:fileHandle = f_open(file);

    if(!file_exists(file))
    {
        err("[loadVehiclesFromFile] File does not exist!", _s("directory", file));
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

    while(f_read(fileHandle, line, sizeof(line)))
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

    f_close(fileHandle);
    return 1;
}
