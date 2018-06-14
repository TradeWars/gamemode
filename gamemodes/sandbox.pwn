// -
// SA:MP Sandbox
// By Southclaws, 2018
// -


#include <a_samp>
#include <logger>
#include <errors>
#include <settings>
#include <requests>


// -
// Internals
// -

#include "sandbox/player/class-selection"
#include "sandbox/player/core"
#include "sandbox/player/account"


// -
// Lifecycle events
// -

public OnScriptInit() {
    log("script initialised");

    new debugs[10][32], total;
    GetSettingStringArray("settings.ini", "debug", "none", debugs, total);

    for(new i; i < total; i++) {
        logger_debug(debugs[i], true);
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
