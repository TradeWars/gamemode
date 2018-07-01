# Saving Data

Persisting data for players is simplified through the use of JSON structures and
a callback mechanism.

Below, is an example of a package that associates a simple variable along with
player data.

This code loads the data when the account is loaded, using the `OnAccountLoaded`
event which is emitted whenever a player's account is loaded. `exists` indicates
the account exists and there is data in `Node:node`. If `exists` is false, then
no data will be available and defaults should be used.

```pawn
static Data[MAX_PLAYERS];
hook OnAccountLoaded(playerid, bool:exists, Node:node) {
    if(exists) {
        new Node:myPackage;
        new ret = JsonGetObject(node, "myPackage", myPackage);
        if(ret) {
            err("failed to read myPackage field", _i("ret", ret));
        }
        JsonGetInt(myPackage, "hello", Data[playerid]);
    } else {
        Data[playerid] = SOME_DEFAULT_VALUE;
    }
}
```

Here is the corresponding storage code for when the player's data is stored. The
event `OnAccountStore` is called whenever a player's data is being saved and it
provides a `Node:` object. This time, the `Node:` object is not for reading but
for writing to. Because `Node:` objects are actually pointers to JSON trees in
the Requests library, you can manipulate their data as if they were passed by
reference (or just an actual pointer in C++).

```pawn
hook OnAccountStore(playerid, Node:node) {
    JsonSetObject(node, "myPackage", JsonObject(
        "hello", JsonInt(Data[playerid])
    );
}
```

In this example, the static variable `Data` has been used to indicate some data
associated with a player. This data could be anything from a single cell to a
complex nested tree of information associated with the player.

Note that this example uses a nested object named `myPackage` with the actual
data stored inside under the `hello` key. Even if your package only stores a
single cell of data with a player, it must store it inside an object.

And that's all you need to associate persistent data with a player. If you add a
brand new field to the JSON structure and submit a Pull Request to the main
repository, you will need to also wait for this object structure to be added to
the SSC server which handles the actual storage of data.
