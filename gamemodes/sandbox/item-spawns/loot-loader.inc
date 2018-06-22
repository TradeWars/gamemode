// loot-loader handles loading item spawn rates from files and assigning them to
// loot-index data structures.

// -
// External Packages
// -

#include <item>
#include <fsutil>
#include <strlib>


// -
// Internal Packages
// -

#include <filesystem>


// -
// Internal
// -

#include <YSI\y_hooks>

#define DIRECTORY_LOOT_TABLES "item-spawns"

hook OnScriptInit() {
    CreateDirIfNotExists("scriptfiles/" DIRECTORY_LOOT_TABLES);
}

hook OnGameModeInit() {
    new total = _item_spawn_readDirectory("scriptfiles/" DIRECTORY_LOOT_TABLES);

    log("loaded loot table entries",
        _i("total", total));
}

_item_spawn_readDirectory(path[])
{
    new
        Directory:directory,
        entry[64],
        ENTRY_TYPE:type,
        ext[5],
        count;

    directory = OpenDir(path);
    if(directory == Directory:-1) {
        err("failed to read directory",
            _s("path", path));
        return 0;
    }

    while(DirNext(directory, type, entry)) {
        if(type == E_DIRECTORY) {
            count += _item_spawn_readDirectory(entry);
        } else if(type == E_REGULAR) {
            PathExt(entry, ext);
            if(!strcmp(ext, ".ltb")) {
                new base[64];
                PathBase(entry, base);
                count += _item_spawn_readFile(base);
            }
        }
    }

    CloseDir(directory);

    return count;
}

_item_spawn_readFile(filename[]) {
    new path[256];
    PathJoin(DIRECTORY_LOOT_TABLES, filename, path);

    if(!fexist(path)) {
        err("no such file or directory",
            _s("path", path));
        return 0;
    }

    new
        File:file = fopen(path, io_read),
        line[128],

        // Loaded from first line
        indexname[32],
        indexid,
        Float:mult,

        // Loaded from each other line
        Float:weight,
        uname[MAX_ITEM_NAME],
        ItemType:itemtype,
        perlimit,
        svrlimit,

        linenum,
        count;

    // read the first line to get the header information
    fread(file, line);
    if(sscanf(line, "p<,>s[32]F(1.0)", indexname, mult)) {
        err("ltb file has bad header, expected: <indexname>, <weight multiplier>",
            _s("path", path));
        return 0;
    }

    indexid = DefineLootIndex(indexname);

    while(fread(file, line)) {
        linenum++;

        strtrim(line, "\r\n");

        if(sscanf(line, "p<,>fs[32]D(3)D(0)", weight, uname, perlimit, svrlimit)) {
            continue;
        }

        itemtype = GetItemTypeFromUniqueName(uname, true);
        if(!IsValidItemType(itemtype)) {
            err("invalid itemtype uname",
                _s("uname", uname),
                _s("path", path),
                _i("linenum", linenum));
            continue;
        }

        AddItemToLootIndex(indexid, itemtype, weight * mult, perlimit, svrlimit);

        count++;
    }

    fclose(file);

    return 1;
}

