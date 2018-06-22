# Contributing

This gamemode follows
[Modern Pawn](https://github.com/Southclaws/sampctl/wiki/Modern-Pawn) standards
and uses sampctl as the build tool and dependency manager. See the readme for
setting up a development environment.

## Structure

### Terminology

#### Packages

A **Package** is a folder containing one or more **Modules**.

Each isolated unit of functionality should be a package. Packages should
communicate via **events** or **exported functions**. A package emits an event
with `CallLocalFunction` to signal to other packages that something happened. A
package may also _export_ functions. Here, _export_ simply means "to make
available". `static` should be used to indicate a function only used within the
immediate **module**.

#### Modules

A **Module** is a single Pawn source file, with an `.inc` extension.

A **Package** may consist of multiple **Modules**, therefore some internal
functions can not use `static` if they are used across different modules in the
same package. When this occurs, functions must use a name style to indicate that
they are _unexported_. See the [function style](#Functions) section for details.

Modules must never expose global variables. Functions must be used instead with,
where appropriate, bounds checking and validity checks.

### Package Structure

In short, follow the
[Pawn Package](https://github.com/Southclaws/sampctl/wiki/Packages) guidelines.

Packages must have a `README.md` file and an "entry point". Internal packages
don't _need_ a `pawn.json` but it can help for testing.

Packages must export all their interface through a single file, the "Entry
Module" or "Entry Script". This module must have the same name as the directory.

### Module Structure

Within an **Entry Module** for a package, there is an order to how sections of
the file are laid out.

Sections are separated by a decorated comment block that looks like this:

```pawn
// -
// Section Title
// -
```

Above a section title should be two blank lines and below should be a single
blank line, for example:

```pawn
(some stuff)


// -
// Another Section
// -

(some other stuff)
```

Modules follow the following order of sections:

- First line should be a comment describing the module
- "External Packages" - Installed packages
- "Internal Packages" - Packages from within the project
- "Declarations" - `new` and `static` variable declarations
- "API" - The function interface that other packages will use
- "Internal" - Internal includes, `static` and non-exported function definitions

Use these mnemonics to help you remember the order: **EIDAI**

- "Einstein Isn't Damn Artificial Intelligence"
- "Everybody Is Definitely An Insect"
- "Ever Imagined Disappearing Away Instantly"

Keeping all the exported functions and events near the top of the file makes it
easier to understand what functionality a package provides.

Non-entry modules (internal modules that are only included by the entry module)
must only declare private and non-exported functions and variables. The "Entry"
module is named that way for a reason.

### Navigating

This project will likely grow quite large, therefore it's essential to document
some tips for navigating the codebase and working with the dependencies.

The project makes heavy use of dependencies. Pawn lacks namespaces so it can be
difficult to know where a function came from if it doesn't follow a prefix
strategy. Currently, the best solution for this is to simply search the entire
project directory for function names. Prepend `stock` to a function to find it's
declaration point.

Most dependencies should be documented. If you find one that isn't, and it's
written by a contributor here, ping them on Discord or open an issue to document
the code some more.

## Style

Contributions should adhere to the style guide. This guide is loosely based on
[this guide](https://tarantool.io/en/doc/1.7/dev_guide/c_style_guide.html) for
the C language with some changes to braces and changes to naming that fit the
Pawn language a bit better.

### Line Length

Lines should be "soft capped" at column 80. Comments should always wrap at
column 80 however code _may_ exceed this limit if it's only a few characters.

Always wrap long function calls or long function declarations.

Strings are fine unless they are ridiculously long, in which case wrap with `\`.

### Braces

K&R braces are preferred:

```pawn
function() {
    //
}
```

However, if you can't shake the muscle memory or your editor forces you, Allman
braces are fine too:

```pawn
function()
{
    //
}
```

#### Switches

Switches must use the same indent level for `case` as the `switch` keyword and
must use braces for multi-line blocks.

```pawn
switch (variable) {
case 0:
    return 0;
case 1:
    return 1;
case 2:
    return 2;
default:
    return -1;
}
```

```pawn
switch (variable) {
case 0: {
    // code...
    return 0;
}
case 1: {
    // code...
    return 1;
}
case 2: {
    // code...
    return 2;
}
default: {
    // code...
    return -1;
}
}
```

### Blocks

Blocks must always use braces, even if only a single line of code exists within
a block. This applies to all levels including functions.

```pawn
func() {
    singleLineExpr();
}
```

```pawn
func() {
    if() {
        singleLineExpr();
    }
}
```

```pawn
func() {
    if() {
        singleLineExpr();
    } else if() {
        //
    } else {
        //
    }
}
```

Switch braces

### Naming

#### Functions

Functions must be named with either:

- `PascalCase` if they are used externally
- `camelCase` if `static` or only used internally within the same package

This makes it easy to tell whether a function call is to another package or
within the same package.

#### Global Variables

Global variables must always use `PascalCase` and must always be `static` unless
declared in the entry module.

Constant globals must use `UPPER_SNAKE_CASE`.

#### Local Variables

Local variables must always use `camelCase` and must never use single letter
names, apart from:

- `i`, `j`, `k`, etc in `for` loops
- `x`, `y`, `z`, etc in geometry contexts

#### Enumerators

Enumerators, if named, must be prefixed with `E_` and use `UPPER_SNAKE_CASE`.
The one exception is when avoiding a `Index tag mismatch` warning, in which case
an `e_` prefix may be used. `UPPER_SNAKE_CASE` must still be used even with the
lower case `e_` prefix.

Enumerator fields must also be `UPPER_SNAKE_CASE` and use the enumerator name as
a prefix.

```pawn
static enum E_PLAYER {
    E_PLAYER_CASH,
    Float:E_PLAYER_HEALTH,
}
```

Enumerators must always be declared `static` unless used outside the module.

#### Macros and Pre-Processor Definitions

Macros must always use `UPPER_SNAKE_CASE` regardless of their usage.

Pre-Processor definitions (constant definitions) must also use
`UPPER_SNAKE_CASE`.

This helps differentiate between variables and constants as well as functions
and macros.

### Documentation

Always document exported functions with a simple line comment in the format
`// FunctionName does X, Y and Z and returns A` where the first word is the name
of the function itself followed by a brief description of what it does. No need
to waste time describing each individual parameter. For example:

```pawn
// LoadPlayerAccount is called to initiate the account load process. This
// function will trigger HTTP calls to get player data, it will display dialogs
// to the player and eventually, once the process has completed, the event
// `OnPlayerLogin` is emitted on success. On failure, the player is kicked.
stock Error:LoadPlayerAccount(playerid) {
    // code...
}
```

Each package should have a `README.md` and, if necessary, each module should
have a comment on the very first line describing what that module provides.

## Adding Things

This mode may differ slightly to other Pawn codebases out there. It's first and
foremost an experiment and testing ground for new development methods.

That being said, I do not wish to discourage anyone from contributing! The whole
point of this new project structure for Pawn is to make the collaboration
process on Pawn projects smoother.

### New Features

When adding a new feature, create a new package for it. The package should have
a brief `README.md` file describing the feature.

Once you've done that, as long as you follow the style guide, and a feature
proposal you can write whatever you want!

#### Handling Persistence

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
