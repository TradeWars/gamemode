# Player Authentication

This package contains API for authenticating players and emitting a storage
event for other packages to contribute data to the player's account.

## Lifecycle

How this works is, when a player connects (or whenever you want),
`LoadPlayerAccount` should be called.

What `LoadPlayerAccount` does is it first makes a call to the database API to
check if the player's account exists. If it does, it gets the data and stores it
then displays a login dialog to the player. If it doesn't exist, a registration
prompt will be displayed.

Assuming a player logs in successfully ("login" here refers to both the process
of authenticating against an existing account or creating a new account, both
these actions are referred to as "logging in") the event `OnPlayerLogin` is
emitted which signals to other packages that the player is ready to join the
game and play.
