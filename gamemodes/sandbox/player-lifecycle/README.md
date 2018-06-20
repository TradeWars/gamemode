# Player Spawn

This is the entry point and the exit point for all players. This package acts as
a gateway for players joining the server and leaving.

This package is responsible for getting the player logged in as well as
triggering the storage routines when they leave.

## Life Cycle

The "Life Cycle" of a player starts when they connect. This is actually handled
inside the `class-selection` package which is a dependency of this one.

This package makes use of `OnPlayerReady` from the `class-selection` package
which is used to trigger the player login flow. Once that flow has completed,
`OnPlayerLogin` is hooked which spawns the player either with default
information or via the data loaded by the authentication package.

## `OnPlayerSpawned`

This package emits the event `OnPlayerSpawned` which indicates the player
successfully authenticated their account, spawned into the game and is ready to
play.
