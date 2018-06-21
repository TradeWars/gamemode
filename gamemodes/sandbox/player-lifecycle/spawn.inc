// Contains all spawns and provides a function to get a new spawn pos that will
// not be the same as the last one that was returned.

#define MAX_SPAWNS (14)

static Float:spawnPositions[MAX_SPAWNS][4] = {
    {-2923.4396, -70.4305,   0.7973, 269.0305},
    {-2914.9213, -902.9458,  0.5190, 339.3433},
    {-2804.5021, -2296.2153, 0.7071, 249.8544},
    {-228.7865,  -1719.8090, 1.1083, 34.9733},
    {13.9133,    -1112.0993, 1.2848, 110.2575},
    {-325.7897,  -467.2996,  1.9922, 48.1126},
    {-71.3649,   -577.1849,  1.3816, 351.6495},
    {161.5016,   157.5428,   1.1178, 187.3177},
    {2012.8952,  -38.5986,   1.2391, 4.8748},
    {2117.7065,  183.7778,   1.0822, 74.3911},
    {-1886.1279, 2160.1945,  1.4039, 335.7922},
    {-764.4365,  654.4160,   1.7907, 1.7156},
    {-434.6048,  867.6434,   1.4236, 318.3918},
    {-638.7510,  1286.1458,  1.4520, 110.0257}
};
static lastSpawn;

getSpawnPosition(&Float:x, &Float:y, &Float:z, &Float:r) {
    new index = random(sizeof(spawnPositions));

    while(index == lastSpawn) {
        index = random(sizeof(spawnPositions));
    }

    x = spawnPositions[index][0];
    y = spawnPositions[index][1];
    z = spawnPositions[index][2];
    r = spawnPositions[index][3];

    lastSpawn = index;
}
