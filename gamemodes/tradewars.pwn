// -
// Trade Wars
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
// Macros
// -

#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))

#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define PRESSING(%0,%1) \
	(%0 & (%1))

#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

// -
// Colors
// -

#define COLOR_ERROR     0xF74A47FF
#define COLOR_INFO      0x2ABAFCFF

#define SCOLOR_ERROR    "{F74A47}"
#define SCOLOR_INFO     "{2ABAFC}"

// -
// External Packages
//

#include <env>
#include <logger>
#include <sscanf2>

native gpci(playerid, serial[], len);


// -
// Global Declarations
// -

new RequestsClient:Warehouse;
new Version[11];


// -
// Internals
// -

#include <gamemode-core>
//#include <world>
#include <player-lifecycle>
#include <vehicles>

#if defined DEV_BUILD
    #include <dev-tools>
#endif


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
        auth[256],
        ret;

    ret = GetEnv("WAREHOUSE_ENDPOINT", endpoint);
    if(ret == 0) {
        fatal("environment variable `WAREHOUSE_ENDPOINT` not set!");
    }

    ret = GetEnv("WAREHOUSE_AUTH", auth);
    if(ret == 0) {
        fatal("environment variable `WAREHOUSE_AUTH` not set!");
    }

    ret = GetEnv("VERSION", Version);
    if(ret == 0) {
        fatal("environment variable `VERSION` not set!");
    }

    log("warehouse configuration", _s("endpoint", endpoint));

    // Create the requests client with the endpoint.
    Warehouse = RequestsClient(endpoint, RequestHeaders(
        "Authorization", auth
    ));
    if(!IsValidRequestsClient(Warehouse)) {
        fatal("failed to create requests client");
    }

    new Error:e = WarehouseIndex(Warehouse);
    if(IsError(e)) {
        fatal("failed to request warehouse index",
            _E(e));
    }

    return 0;
}

public OnWarehouseIndex(bool:success, message[], Error:error, Node:result) {
    if(!success) {
        fatal("failed to get warehouse index",
            _s("message", message));
    } else {
        log("successfully connected to warehouse",
            _s("message", message),
            _s("version", Version));
    }
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
