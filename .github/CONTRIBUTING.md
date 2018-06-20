# Contributing

This gamemode follows
[Modern Pawn](https://github.com/Southclaws/sampctl/wiki/Modern-Pawn) standards
and uses sampctl as the build tool and dependency manager. See the readme for
setting up a development environment.

## Structure

A **Module** is a single Pawn source file, with an `.inc` extension.

A **Package** is a folder containing one or more **Modules**.

Each isolated unit of functionality should be a package. Packages should
communicate via **events** or **exported functions**. A package emits an event
with `CallLocalFunction` to signal to other packages that something happened. A
package may also _export_ functions. Here, _export_ simply means "to make
available". `static` should be used to indicate a function only used within the
immediate **module**.

A **Package** may consist of multiple **Modules**, therefore some internal
functions can not use `static` if they are used across different modules in the
same package. When this occurs, functions must use a name style to indicate that
they are _unexported_. See the [function style](#Functions) section for details.

Modules must never expose global variables. Functions must be used instead with,
where appropriate, bounds checking and validity checks.

## Style

Contributions should adhere to the style guide. This guide is loosely based on
[this guide](https://tarantool.io/en/doc/1.7/dev_guide/c_style_guide.html) for
the C language with some changes to braces and changes to naming that fit the
Pawn language a bit better.

### Braces

K&R braces are preferred:

```pawn
function() {
    //
}
```

However, if you can't shake the muscle memory or your editor forces you, Allman
braces are allowed too:

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
    return 0;
}
case 1: {
    return 1;
}
case 2: {
    return 2;
}
default: {
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
