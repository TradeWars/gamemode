// Provides a function to toggle airbreak and handles the airbeak.

// -
// External Packages
// -

#include <Pawn.CMD>

#include <YSI\y_hooks>

// -
// Declaration
// -

#define AIRBREAK_SPEEDUP_KEY        KEY_JUMP
#define AIRBREAK_SLOWDOWN_KEY       KEY_WALK
#define AIRBREAK_MOVEUP_KEY         KEY_FIRE
#define AIRBREAK_MOVEDOWN_KEY       KEY_HANDBRAKE
#define AIRBREAK_SPEED_MULTIPLIER   (2.0)

new isAirbreakEnabled[MAX_PLAYERS];

// -
// API
// -

// Toggles the players airbreak state (on/off) and returns the
// new state.
TogglePlayerAirbreak(playerid)
{
    isAirbreakEnabled[playerid] = !isAirbreakEnabled[playerid];
    return isAirbreakEnabled[playerid];
}

// -
// Internal
// -

hook OnPlayerUpdate(playerid)
{
    if(isAirbreakEnabled[playerid])
    {
        new keys, upDown, leftRight,
            Float:vX, Float:vY, Float:vZ,
            Float:fvX, Float:fvY, Float:fvZ;

        GetPlayerKeys(playerid, keys, upDown, leftRight);
        GetPlayerCameraFrontVector(playerid, fvX, fvY, fvZ);

        if(keys & AIRBREAK_MOVEUP_KEY)
        {
            vZ = 1.0;
        }
        else if(keys & AIRBREAK_MOVEDOWN_KEY)
        {
            vZ = -0.25;
        }

        if(upDown == KEY_UP)
        {
            vX = fvX;
            vY = fvY;
        }
        else if(upDown == KEY_DOWN)
        {
            vX = -fvX;
            vY = -fvY;
        }

        if(keys & AIRBREAK_SPEEDUP_KEY)
        {
            vX *= AIRBREAK_SPEED_MULTIPLIER;
            vY *= AIRBREAK_SPEED_MULTIPLIER;
            vZ *= AIRBREAK_SPEED_MULTIPLIER;
        }
        else if(keys & AIRBREAK_SLOWDOWN_KEY)
        {
            vX /= AIRBREAK_SPEED_MULTIPLIER;
            vY /= AIRBREAK_SPEED_MULTIPLIER;
            vZ /= AIRBREAK_SPEED_MULTIPLIER;
        }

        SetPlayerVelocity(playerid, vX, vY, vZ);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}
