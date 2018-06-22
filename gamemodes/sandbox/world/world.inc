// world manages setting up the game world and creating all necessary entities
// across the game map.

// -
// Internal Packages
// -

#include <item>
#include <item-spawns>


// -
// Declarations
// -

static
    MapName[32] = "San Androcalypse",
    ItemCounts[MAX_ITEM_TYPE],
    bool:ServerInitialising;


// -
// API
// -

stock bool:IsServerInitialising() {
    return ServerInitialising;
}

stock GetMapName() {
    return MapName;
}


// -
// Internal
// -

// #include "sss/world/houseloot"
// #include "sss/world/xmas"

#include <YSI\y_hooks>


hook OnGameModeInit() {
    ServerInitialising = true;

    // store this to a list and compare after
    for(new ItemType:i; i < MAX_ITEM_TYPE; i++) {
        if(!IsValidItemType(i)) {
            break;
        }

        if(GetItemTypeCount(i) == 0) {
            continue;
        }

        ItemCounts[i] = GetItemTypeCount(i);
    }

    defer _Load_LS();
}

// #include "regions/ls"
timer _Load_LS[500]() {
//     Load_LS();
    defer _Load_RC();
}

// #include "regions/rc"
timer _Load_RC[500]() {
//     Load_RC();
    defer _Load_FC();
}

// #include "regions/fc"
timer _Load_FC[500]() {
//     Load_FC();
    defer _Load_SF();
}

#include "regions/sf"
timer _Load_SF[500]() {
    Load_SF();
    defer _Load_TR();
}

// #include "regions/tr"
timer _Load_TR[500]() {
//     Load_TR();
    defer _Load_BC();
}

// #include "regions/bc"
timer _Load_BC[500]() {
//     Load_BC();
    defer _Load_LV();
}

// #include "regions/lv"
timer _Load_LV[500]() {
//     Load_LV();
    defer _Finalise();
}

timer _Finalise[500]() {
    new itemTypeName[MAX_ITEM_NAME];

    // compare with previous list and print differences
    for(new ItemType:itemType; itemType < MAX_ITEM_TYPE; itemType++) {
        if(!IsValidItemType(itemType)) {
            break;
        }

        if(GetItemTypeCount(itemType) == 0) {
            continue;
        }

        GetItemTypeUniqueName(itemType, itemTypeName);

        log("item statistics",
            _i("type", _:itemType),
            _s("name", itemTypeName),
            _i("preloot", ItemCounts[itemType]),
            _i("postloot", GetItemTypeCount(itemType) - ItemCounts[itemType]),
            _i("total", GetItemTypeCount(itemType))
        );
    }

    ServerInitialising = false;
}
