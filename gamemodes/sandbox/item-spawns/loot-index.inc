// loot-index provides a way of spawning random items according to rarity rules
// which can be added at runtime.


#include <YSI\y_hooks>


// -
// Declarations
// -

#define MAX_LOOT_INDEX			(15)
#define MAX_LOOT_INDEX_ITEMS	(256)
#define MAX_LOOT_INDEX_NAME		(32)
#define MAX_LOOT_SPAWN			(12683)
#define MAX_ITEMS_PER_SPAWN		(6)


enum E_LOOT_INDEX_ITEM_DATA {
    ItemType:lootitem_type,
    Float:lootitem_weight,
    lootitem_limit
}

enum E_LOOT_SPAWN_DATA {
    Float:loot_posX,
    Float:loot_posY,
    Float:loot_posZ,
    loot_world,
    loot_interior,
    Float:loot_weight,
    loot_size,
    loot_index,

    Item:loot_items[MAX_ITEMS_PER_SPAWN],
    loot_total
}


static
    loot_IndexTotal,
    loot_IndexSize[MAX_LOOT_INDEX],
    loot_IndexItems[MAX_LOOT_INDEX][MAX_LOOT_INDEX_ITEMS][E_LOOT_INDEX_ITEM_DATA],
    loot_IndexName[MAX_LOOT_INDEX][MAX_LOOT_INDEX_NAME],

    loot_SpawnData[MAX_LOOT_SPAWN][E_LOOT_SPAWN_DATA],
    loot_SpawnTotal,

    loot_ItemTypeLimit[MAX_ITEM_TYPE],
    loot_ItemLootIndex[MAX_ITEM] = {-1, ...},

    Float:loot_SpawnMult = 1.0;


// -
// API
// -

stock DefineLootIndex(name[MAX_LOOT_INDEX_NAME]) {
    if(loot_IndexTotal >= MAX_LOOT_INDEX) {
        err("failed to add new loot index, limit reached",
            _i("limit", MAX_LOOT_INDEX),
            _s("name", name));
    }

    loot_IndexName[loot_IndexTotal] = name;

    return loot_IndexTotal++;
}

stock AddItemToLootIndex(index, ItemType:itemtype, Float:weight, perspawnlimit = 3, serverspawnlimit = 0) {
    if(index > loot_IndexTotal) {
        err("invalid index specified",
            _i("index", index));
        return 0;
    }

    if(loot_IndexSize[index] >= MAX_LOOT_INDEX_ITEMS) {
        err("loot index item limit reached");
    }

    loot_IndexItems[index][loot_IndexSize[index]][lootitem_type] = itemtype;
    loot_IndexItems[index][loot_IndexSize[index]][lootitem_weight] = weight;
    loot_IndexItems[index][loot_IndexSize[index]][lootitem_limit] = perspawnlimit;
    
    loot_ItemTypeLimit[itemtype] = serverspawnlimit;

    loot_IndexSize[index] += 1;

    return 1;
}

stock CreateStaticLootSpawn(Float:x, Float:y, Float:z, lootindex, Float:weight, size = -1, worldid = 0, interiorid = 0)
{
    if(loot_SpawnTotal >= MAX_LOOT_SPAWN - 1)
    {
        err("Loot spawn limit reached.");
        return -1;
    }

    if(!(0 <= lootindex < loot_IndexTotal))
    {
        err("invalid loot index",
            _i("index", lootindex));
        return -1;
    }

    if(size > MAX_ITEMS_PER_SPAWN)
        size = -1;

    if(size == -1)
        size = MAX_ITEMS_PER_SPAWN / 2 + random(MAX_ITEMS_PER_SPAWN / 2);

    new lootspawnid = loot_SpawnTotal;

    loot_SpawnData[lootspawnid][loot_posX] = x;
    loot_SpawnData[lootspawnid][loot_posY] = y;
    loot_SpawnData[lootspawnid][loot_posZ] = z;
    loot_SpawnData[lootspawnid][loot_world] = worldid;
    loot_SpawnData[lootspawnid][loot_interior] = interiorid;
    loot_SpawnData[lootspawnid][loot_weight] = weight;
    loot_SpawnData[lootspawnid][loot_size] = size;
    loot_SpawnData[lootspawnid][loot_index] = lootindex;

    new
        ItemType:sampleList[MAX_LOOT_INDEX_ITEMS],
        sampleListSize,
        ItemType:itemtype,
        Item:itemid,
        Float:rot = frandom(360.0);

    sampleListSize = _loot_GenerateSampleList(sampleList, lootindex);

    if(sampleListSize == 0)
        return -1;

    // log("[CreateStaticLootSpawn] index %d size %d: %s", lootindex, sampleListSize, atosr(_:sampleList, sampleListSize));

    for(new i; i < size; i++)
    {
        if(frandom(100.0) > weight * loot_SpawnMult)
            continue;

        // Generate an item from the sample list
        if(!_loot_PickFromSampleList(sampleList, sampleListSize, itemtype))
            continue;

        if(itemtype == item_NULL)
        {
            err("null type chosen",
                _i("lootindex", lootindex),
                _i("sampleListSize", sampleListSize)
            );
            continue;
        }

        // Check if the generated item is legal
        if(loot_ItemTypeLimit[itemtype] > 0 && GetItemTypeCount(itemtype) > loot_ItemTypeLimit[itemtype])
            continue;

        // Create the item
        itemid = GetNextItemID();

        if(!(Item:0 <= itemid < MAX_ITEM))
        {
            err("Item limit reached while generating loot.");
            return -1;
        }

        loot_ItemLootIndex[itemid] = lootindex;

        CreateItem(itemtype,
            x + (frandom(1.0) * floatsin(((360 / size) * i) + rot, degrees)),
            y + (frandom(1.0) * floatcos(((360 / size) * i) + rot, degrees)),
            z, .rz = frandom(360.0), .world = worldid, .interior = interiorid);

        loot_SpawnData[lootspawnid][loot_items][loot_SpawnData[lootspawnid][loot_total]] = itemid;
        loot_SpawnData[lootspawnid][loot_total]++;
    }

    return loot_SpawnTotal++;
}

stock CreateLootItem(lootindex, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0, worldid = 0, interiorid = 0)
{
    if(!(0 <= lootindex < loot_IndexTotal))
    {
        err("Loot index (%d) is invalid.", lootindex);
        return -1;
    }

    new
        ItemType:sampleList[MAX_LOOT_INDEX_ITEMS],
        sampleListSize,
        ItemType:itemtype;

    sampleListSize = _loot_GenerateSampleList(sampleList, lootindex);

    if(sampleListSize == 0)
        return -1;

    // Generate an item from the sample list
    if(!_loot_PickFromSampleList(sampleList, sampleListSize, itemtype))
        return INVALID_ITEM_ID;

    if(itemtype == item_NULL)
    {
        err("Chosen cell contained itemtype 0, index %d size %d: %s", lootindex, sampleListSize, atosr(_:sampleList, sampleListSize));
        return INVALID_ITEM_ID;
    }

    if(loot_ItemTypeLimit[itemtype] > 0 && GetItemTypeCount(itemtype) > loot_ItemTypeLimit[itemtype])
        return INVALID_ITEM_ID;

    new itemid = GetNextItemID();

    if(!(0 <= itemid < ITM_MAX))
        return INVALID_ITEM_ID;

    loot_ItemLootIndex[itemid] = lootindex;

    CreateItem(itemtype, x, y, z, .rz = frandom(360.0), .world = worldid, .interior = interiorid);

    return itemid;
}

stock FillContainerWithLoot(containerid, slots, lootindex)
{
    if(!(0 <= lootindex < loot_IndexTotal))
    {
        err("Loot index (%d) is invalid.", lootindex);
        return -1;
    }

    // log("[FillContainerWithLoot] containerid %d, slots %d, lootindex %d", containerid, slots, lootindex);
    new containersize = GetContainerSize(containerid);

    if(slots > containersize)
        slots = containersize;

    else if(slots <= 0)
        return 0;

    new
        ItemType:sampleList[MAX_LOOT_INDEX_ITEMS],
        sampleListSize,
        items,
        itemid,
        ItemType:itemtype;

    sampleListSize = _loot_GenerateSampleList(sampleList, lootindex);

    if(sampleListSize == 0)
        return 0;

    while(items < slots && sampleListSize > 0 && GetContainerFreeSlots(containerid) > 0)
    {
        // Generate an item from the sample list

        if(!_loot_PickFromSampleList(sampleList, sampleListSize, itemtype))
            continue;

        if(itemtype == item_NULL)
        {
            err("Chosen cell contained itemtype 0, index %d size %d: %s", lootindex, sampleListSize, atosr(_:sampleList, sampleListSize));
            continue;
        }

        // Check if the generated item is legal
        if(loot_ItemTypeLimit[itemtype] > 0 && GetItemTypeCount(itemtype) >= loot_ItemTypeLimit[itemtype])
        {
            continue;
        }

        // Create the item
        itemid = GetNextItemID();

        if(!(0 <= itemid < ITM_MAX))
        {
            err("Item limit reached while generating loot.");
            return -1;
        }

        loot_ItemLootIndex[itemid] = lootindex;

        // allocate the item first
        itemid = AllocNextItemID(itemtype);
        // add it to the container before creating
        AddItemToContainer(containerid, itemid);
        // now OnItemCreate will return a value for GetItemContainer :)
        CreateItem_ExplicitID(itemid);

        items++;
    }

    return 1;
}

stock IsValidLootIndex(index) {
    return (0 <= index < loot_IndexTotal);
}

stock GetItemLootIndex(itemid) {
    if(!IsValidItem(itemid)) {
        return -1;
    }

    return loot_ItemLootIndex[itemid];
}

stock GetLootSpawnPos(lootspawn, &Float:x, &Float:y, &Float:z) {
    x = loot_SpawnData[lootspawn][loot_posX];
    y = loot_SpawnData[lootspawn][loot_posY];
    z = loot_SpawnData[lootspawn][loot_posZ];
    return 1;
}

stock GetLootSpawnWorld(lootspawn) {
    return loot_SpawnData[lootspawn][loot_world];
}

stock GetLootSpawnInterior(lootspawn) {
    return loot_SpawnData[lootspawn][loot_interior];
}

stock GetLootSpawnWeight(lootspawn) {
    return loot_SpawnData[lootspawn][loot_weight];
}

stock GetLootSpawnSize(lootspawn) {
    return loot_SpawnData[lootspawn][loot_size];
}

stock GetLootSpawnIndex(lootspawn) {
    return loot_SpawnData[lootspawn][loot_index];
}

stock GetLootSpawnItems(lootspawn) {
    return loot_SpawnData[lootspawn][loot_items];
}

stock GetLootSpawnTotalItems(lootspawn) {
    return loot_SpawnData[lootspawn][loot_total];
}

stock GetLootIndexFromName(name[]) {
    for(new i; i < loot_IndexTotal; i++) {
        if(!strcmp(name, loot_IndexName[i], true)) {
            return i;
        }
    }

    err("specified index name is invalid",
        _s("name", name));

    return -1;
}

// -
// Internal
// -

_loot_GenerateSampleList(ItemType:list[MAX_LOOT_INDEX_ITEMS], lootindex)
{
    new size;

    for(new i; i < loot_IndexSize[lootindex]; ++i)
    {
        if(frandom(100.0) > loot_IndexItems[lootindex][i][lootitem_weight])
            continue;

        if(loot_IndexItems[lootindex][i][lootitem_type] == item_NULL)
        {
            // log("[_loot_GenerateSampleList] Prevented entering NULL ITEM into sampleList");
            continue;
        }

        list[size++] = loot_IndexItems[lootindex][i][lootitem_type];
    }

    // log("[_loot_GenerateSampleList] Generated: %s", atosr(_:list, size));

    return size;
}

_loot_PickFromSampleList(ItemType:list[MAX_LOOT_INDEX_ITEMS], &listsize, &ItemType:itemtype)
{
    if(listsize <= 0)
        return -1;

    new cell = random(listsize);
    itemtype = list[cell];

    for(new i = cell; i < listsize - 1; i++)
        list[i] = list[i+1];

    listsize -= 1;

    return 1;
}

/*
_loot_LootSpawnItemsOfType(lootspawnid, ItemType:itemtype)
{
    new count;

    for(new i; i < loot_SpawnData[lootspawnid][loot_total]; i++)
    {
        if(GetItemType(loot_SpawnData[lootspawnid][loot_items][i]) == itemtype)
            count++;
    }
    // log("[_loot_LootSpawnItemsOfType] loot spawn %d contains %d of %d", lootspawnid, count, _:itemtype);
    return count;
}

_loot_ContainerItemsOfType(containerid, ItemType:itemtype)
{
    new count;

    for(new i, j = GetContainerSize(containerid); i < j; i++)
    {
        if(GetItemType(GetContainerSlotItem(containerid, i)) == itemtype)
            count++;
    }
    // log("[_loot_ContainerItemsOfType] container %d contains %d of %d", containerid, count, _:itemtype);
    return count;
}
*/
hook OnItemDestroy(Item:itemid) {
    loot_ItemLootIndex[itemid] = -1;
    return Y_HOOKS_CONTINUE_RETURN_0;
}

// TODO: integrate weapon spawn data somehow
//
// hook OnItemCreate(itemid)
// {
//     new lootindex = GetItemLootIndex(itemid);

//     if(lootindex != -1)
//     {
//         new ammotype = GetItemTypeAmmoType(GetItemType(itemid));
//         if(ammotype != -1) {
//             SetItemExtraData(itemid, ammo_Data[ammotype][ammo_size] == 1 ? random(1) : random(ammo_Data[ammotype][ammo_size] - 1) + 1);
//         }

//         new ItemType:itemtype = GetItemType(itemid);

//         if(GetItemTypeWeapon(itemtype) != -1)
//         {
//             new calibre = GetItemTypeWeaponCalibre(itemtype);
//             if(calibre != NO_CALIBRE)
//             {
//                 new
//                     ItemType:ammotypelist[4],
//                     ammotypes;

//                 ammotypes = GetAmmoItemTypesOfCalibre(calibre, ammotypelist);

//                 if(ammotypes > 0)
//                 {
//                     new magsize = GetItemTypeWeaponMagSize(itemtype);

//                     if(lootindex == GetLootIndexFromName("world_civilian") || lootindex == GetLootIndexFromName("vehicle_civilian") || lootindex == GetLootIndexFromName("world_survivor"))
//                     {
//                         SetItemWeaponItemMagAmmo(itemid, random(magsize));
//                         SetItemWeaponItemAmmoItem(itemid, ammotypelist[random(ammotypes)]);
//                     }
//                     else if(lootindex == GetLootIndexFromName("world_police") || lootindex == GetLootIndexFromName("world_military") || lootindex == GetLootIndexFromName("vehicle_police") || lootindex == GetLootIndexFromName("vehicle_military") || lootindex == GetLootIndexFromName("airdrop_low_weapons") || lootindex == GetLootIndexFromName("airdrop_military_weapons"))
//                     {
//                         switch(random(100))
//                         {
//                             case 00..29: // spawn empty
//                             {
//                                 SetItemWeaponItemMagAmmo(itemid, 0);
//                                 SetItemWeaponItemAmmoItem(itemid, INVALID_ITEM_TYPE);
//                             }

//                             case 30..49: // spawn with random ammo
//                             {
//                                 SetItemWeaponItemMagAmmo(itemid, random(magsize + 1) - 1);
//                                 SetItemWeaponItemAmmoItem(itemid, ammotypelist[random(ammotypes)]);
//                             }

//                             case 50..99: // spawn full
//                             {
//                                 SetItemWeaponItemMagAmmo(itemid, magsize);
//                                 SetItemWeaponItemAmmoItem(itemid, ammotypelist[random(ammotypes)]);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }
