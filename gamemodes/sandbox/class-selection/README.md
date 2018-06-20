# Class Selection Override

This simple package overrides the default class selection and provides a new
event to use instead of `OnPlayerSpawn`.

When using this package, do not use `OnPlayerSpawn` in your codebase because it
will be called twice upon connect and death.

Instead, use `OnPlayerReady`, an event emitted by this package that signals that
the player has fully spawned and control is ready to be taken back by the
gamemode.
