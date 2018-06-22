// -
// SA:MP Sandbox
// By Southclaws, 2018
// -


#include <a_samp>


// -
// Compiletime Configuration
// -

#undef MAX_PLAYERS
#define MAX_PLAYERS (32)
#define MAX_ITEM_TYPE (ItemType:300)
#define MAX_BUTTON (Button:32768)
#define MAX_ITEM (Item:32768)
#define MAX_CONTAINER_SLOTS (100)


// -
// External Packages
//

#include <logger>
#include <sscanf2>

native gpci(playerid, serial[], len);


// -
// Global Declarations
// -

new RequestsClient:storeClient;


// -
// Internals
// -

#include <gamemode-core>
//#include <world>
#include <player-lifecycle>
#include <vehicles>


// -
// Lifecycle events
// -

public OnScriptInit() {
    log("script initialised");

    // Load debug logging levels
    new debugs[10][32], total;
    GetSettingStringArray("settings.ini", "debug", "none", debugs, total);

    for(new i; i < total; i++) {
        logger_debug(debugs[i], true);
    }

    // Set up the Requests HTTP client
    new
        endpoint[128],
        auth[64];

    GetSettingString("settings.ini", "endpoint", "http://localhost:7788", endpoint);
    GetSettingString("settings.ini", "auth", "cunning_fox", auth);

    // Create the requests client with the endpoint.
    storeClient = RequestsClient(endpoint, RequestHeaders(
        "Authorization", auth
    ));
    if(!IsValidRequestsClient(storeClient)) {
        fatal("failed to create requests client");
    }

    return 0;
}

public OnGameModeInit() {
    log("gamemode initialised");

    AddPlayerClass(0, DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_POS_Z, 0.0, 0, 0, 0, 0, 0, 0);

    return 0;
}

public OnGameModeExit() {
    log("gamemode exited");

    return 0;
}

main() {
    log("script ready");
}
