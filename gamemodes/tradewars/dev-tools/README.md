# Development tools

This package provides commands/utilities that can help during development.

# Commands

* `/tp [id] OR /tp [id] [id]`
  * Teleports a player to another player
* `/tpcoords [x] [y] [z] [playerid = -1]`
  * Teleports a player to the specified coordinates.
* `/tpinterior [interiorid] [playerid]`
  * Teleports a player to the specified interior.
* `/weapon [playerid] [weaponid] [ammo = 50]`
  * Gives a player the specified weapon.
* `/createveh [model] [color1 = -1] [color2 = -1]`
  * Creates a vehicle at the players current position and him/her in it.
* `/airbreak`
  * Toggles the players airbreak state.

# Airbreak configuration

You can easily change the airbreak controls or speed if you wish.
`dev-airbreak.inc` contains compiletime configurations in the `declaration`
section.

# API

## Functions

## `TogglePlayerAirbreak (playerid)`

This function toggles the players airbreak state (on/off) and returns the
new state.

**This function returns :**
* **0/1** The new airbreak state.
