// gamemode-core handles initialisation of core, global, shared gameplay
// features such as items, vehicles and anything else that's widely used across
// the entire codebase and considered a core element to the game rather than a
// feature that can be toggled on or off.
//
// These elements are all to be initialised inside `OnScriptInit` making it a
// safe assumption that these resources are ready to use in `OnGameModeInit`.

#include "init"
#include "itemtypes"