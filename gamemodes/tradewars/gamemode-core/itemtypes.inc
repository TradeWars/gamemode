// itemtypes contains all `DefineItemType` calls and `ItemType:` declarations.
// After item types are defined, item type bindings for characteristics are to
// be set at the end of the `OnScriptInit` call.

#include <item>
#include <YSI\y_hooks>


new stock
// 00
ItemType:		item_NULL			= INVALID_ITEM_TYPE,
ItemType:		item_Knuckles		= INVALID_ITEM_TYPE,
ItemType:		item_GolfClub		= INVALID_ITEM_TYPE,
ItemType:		item_Baton			= INVALID_ITEM_TYPE,
ItemType:		item_Knife			= INVALID_ITEM_TYPE,
ItemType:		item_Bat			= INVALID_ITEM_TYPE,
ItemType:		item_Spade			= INVALID_ITEM_TYPE,
ItemType:		item_PoolCue		= INVALID_ITEM_TYPE,
ItemType:		item_Sword			= INVALID_ITEM_TYPE,
ItemType:		item_Chainsaw		= INVALID_ITEM_TYPE,
// 10
ItemType:		item_Dildo1			= INVALID_ITEM_TYPE,
ItemType:		item_Dildo2			= INVALID_ITEM_TYPE,
ItemType:		item_Dildo3			= INVALID_ITEM_TYPE,
ItemType:		item_Dildo4			= INVALID_ITEM_TYPE,
ItemType:		item_Flowers		= INVALID_ITEM_TYPE,
ItemType:		item_WalkingCane	= INVALID_ITEM_TYPE,
ItemType:		item_Grenade		= INVALID_ITEM_TYPE,
ItemType:		item_Teargas		= INVALID_ITEM_TYPE,
ItemType:		item_Molotov		= INVALID_ITEM_TYPE,
ItemType:		item_NULL2			= INVALID_ITEM_TYPE,
// 20
ItemType:		item_NULL3			= INVALID_ITEM_TYPE,
ItemType:		item_NULL4			= INVALID_ITEM_TYPE,
ItemType:		item_M9Pistol		= INVALID_ITEM_TYPE,
ItemType:		item_M9PistolSD		= INVALID_ITEM_TYPE,
ItemType:		item_DesertEagle	= INVALID_ITEM_TYPE,
ItemType:		item_PumpShotgun	= INVALID_ITEM_TYPE,
ItemType:		item_Sawnoff		= INVALID_ITEM_TYPE,
ItemType:		item_Spas12			= INVALID_ITEM_TYPE,
ItemType:		item_Mac10			= INVALID_ITEM_TYPE,
ItemType:		item_MP5			= INVALID_ITEM_TYPE,
// 30
ItemType:		item_WASR3Rifle		= INVALID_ITEM_TYPE,
ItemType:		item_M16Rifle		= INVALID_ITEM_TYPE,
ItemType:		item_Tec9			= INVALID_ITEM_TYPE,
ItemType:		item_SemiAutoRifle	= INVALID_ITEM_TYPE,
ItemType:		item_SniperRifle	= INVALID_ITEM_TYPE,
ItemType:		item_RocketLauncher	= INVALID_ITEM_TYPE,
ItemType:		item_Heatseeker		= INVALID_ITEM_TYPE,
ItemType:		item_Flamer			= INVALID_ITEM_TYPE,
ItemType:		item_Minigun		= INVALID_ITEM_TYPE,
ItemType:		item_RemoteBomb		= INVALID_ITEM_TYPE,
// 40
ItemType:		item_Detonator		= INVALID_ITEM_TYPE,
ItemType:		item_SprayPaint		= INVALID_ITEM_TYPE,
ItemType:		item_Extinguisher	= INVALID_ITEM_TYPE,
ItemType:		item_Camera			= INVALID_ITEM_TYPE,
ItemType:		item_NightVision	= INVALID_ITEM_TYPE,
ItemType:		item_ThermalVision	= INVALID_ITEM_TYPE,
ItemType:		item_Parachute		= INVALID_ITEM_TYPE,
ItemType:		item_Medkit			= INVALID_ITEM_TYPE,
ItemType:		item_HardDrive		= INVALID_ITEM_TYPE,
ItemType:		item_Key			= INVALID_ITEM_TYPE,
// 50
ItemType:		item_FireworkBox	= INVALID_ITEM_TYPE,
ItemType:		item_FireLighter	= INVALID_ITEM_TYPE,
ItemType:		item_Timer			= INVALID_ITEM_TYPE,
ItemType:		item_Explosive		= INVALID_ITEM_TYPE,
ItemType:		item_TntTimebomb	= INVALID_ITEM_TYPE,
ItemType:		item_Battery		= INVALID_ITEM_TYPE,
ItemType:		item_Fusebox		= INVALID_ITEM_TYPE,
ItemType:		item_Bottle			= INVALID_ITEM_TYPE,
ItemType:		item_Sign			= INVALID_ITEM_TYPE,
ItemType:		item_Armour			= INVALID_ITEM_TYPE,
// 60
ItemType:		item_Bandage		= INVALID_ITEM_TYPE,
ItemType:		item_FishRod		= INVALID_ITEM_TYPE,
ItemType:		item_Wrench			= INVALID_ITEM_TYPE,
ItemType:		item_Crowbar		= INVALID_ITEM_TYPE,
ItemType:		item_Hammer			= INVALID_ITEM_TYPE,
ItemType:		item_Shield			= INVALID_ITEM_TYPE,
ItemType:		item_Flashlight		= INVALID_ITEM_TYPE,
ItemType:		item_StunGun		= INVALID_ITEM_TYPE,
ItemType:		item_LaserPoint		= INVALID_ITEM_TYPE,
ItemType:		item_Screwdriver	= INVALID_ITEM_TYPE,
// 70
ItemType:		item_MobilePhone	= INVALID_ITEM_TYPE,
ItemType:		item_Pager			= INVALID_ITEM_TYPE,
ItemType:		item_Rake			= INVALID_ITEM_TYPE,
ItemType:		item_HotDog			= INVALID_ITEM_TYPE,
ItemType:		item_EasterEgg		= INVALID_ITEM_TYPE,
ItemType:		item_Cane			= INVALID_ITEM_TYPE,
ItemType:		item_HandCuffs		= INVALID_ITEM_TYPE,
ItemType:		item_Bucket			= INVALID_ITEM_TYPE,
ItemType:		item_GasMask		= INVALID_ITEM_TYPE,
ItemType:		item_Flag			= INVALID_ITEM_TYPE,
// 80
ItemType:		item_DoctorBag		= INVALID_ITEM_TYPE,
ItemType:		item_Backpack		= INVALID_ITEM_TYPE,
ItemType:		item_Satchel		= INVALID_ITEM_TYPE,
ItemType:		item_Wheel			= INVALID_ITEM_TYPE,
ItemType:		item_MotionSense	= INVALID_ITEM_TYPE,
ItemType:		item_Accelerometer	= INVALID_ITEM_TYPE,
ItemType:		item_TntProxMine	= INVALID_ITEM_TYPE,
ItemType:		item_IedBomb		= INVALID_ITEM_TYPE,
ItemType:		item_Pizza			= INVALID_ITEM_TYPE,
ItemType:		item_Burger			= INVALID_ITEM_TYPE,
// 90
ItemType:		item_BurgerBox		= INVALID_ITEM_TYPE,
ItemType:		item_Taco			= INVALID_ITEM_TYPE,
ItemType:		item_GasCan			= INVALID_ITEM_TYPE,
ItemType:		item_Clothes		= INVALID_ITEM_TYPE,
ItemType:		item_HelmArmy		= INVALID_ITEM_TYPE,
ItemType:		item_MediumBox		= INVALID_ITEM_TYPE,
ItemType:		item_SmallBox		= INVALID_ITEM_TYPE,
ItemType:		item_LargeBox		= INVALID_ITEM_TYPE,
ItemType:		item_HockeyMask		= INVALID_ITEM_TYPE,
ItemType:		item_Meat			= INVALID_ITEM_TYPE,
// 100
ItemType:		item_DeadLeg		= INVALID_ITEM_TYPE,
ItemType:		item_Torso			= INVALID_ITEM_TYPE,
ItemType:		item_LongPlank		= INVALID_ITEM_TYPE,
ItemType:		item_GreenGloop		= INVALID_ITEM_TYPE,
ItemType:		item_Capsule		= INVALID_ITEM_TYPE,
ItemType:		item_RadioPole		= INVALID_ITEM_TYPE,
ItemType:		item_SignShot		= INVALID_ITEM_TYPE,
ItemType:		item_Mailbox		= INVALID_ITEM_TYPE,
ItemType:		item_Pumpkin		= INVALID_ITEM_TYPE,
ItemType:		item_Nailbat		= INVALID_ITEM_TYPE,
// 110
ItemType:		item_ZorroMask		= INVALID_ITEM_TYPE,
ItemType:		item_Barbecue		= INVALID_ITEM_TYPE,
ItemType:		item_Headlight		= INVALID_ITEM_TYPE,
ItemType:		item_Pills			= INVALID_ITEM_TYPE,
ItemType:		item_AutoInjec		= INVALID_ITEM_TYPE,
ItemType:		item_BurgerBag		= INVALID_ITEM_TYPE,
ItemType:		item_CanDrink		= INVALID_ITEM_TYPE,
ItemType:		item_Detergent		= INVALID_ITEM_TYPE,
ItemType:		item_Dice			= INVALID_ITEM_TYPE,
ItemType:		item_Dynamite		= INVALID_ITEM_TYPE,
// 120
ItemType:		item_Door			= INVALID_ITEM_TYPE,
ItemType:		item_MetPanel		= INVALID_ITEM_TYPE,
ItemType:		item_MetalGate		= INVALID_ITEM_TYPE,
ItemType:		item_CrateDoor		= INVALID_ITEM_TYPE,
ItemType:		item_CorPanel		= INVALID_ITEM_TYPE,
ItemType:		item_ShipDoor		= INVALID_ITEM_TYPE,
ItemType:		item_InsulDoor		= INVALID_ITEM_TYPE,
ItemType:		item_InsulPanel		= INVALID_ITEM_TYPE,
ItemType:		item_SmallPanel		= INVALID_ITEM_TYPE,
ItemType:		item_WoodPanel		= INVALID_ITEM_TYPE,
// 130
ItemType:		item_Flare			= INVALID_ITEM_TYPE,
ItemType:		item_TntPhoneBomb	= INVALID_ITEM_TYPE,
ItemType:		item_ParaBag		= INVALID_ITEM_TYPE,
ItemType:		item_Keypad			= INVALID_ITEM_TYPE,
ItemType:		item_TentPack		= INVALID_ITEM_TYPE,
ItemType:		item_Campfire		= INVALID_ITEM_TYPE,
ItemType:		item_CowboyHat		= INVALID_ITEM_TYPE,
ItemType:		item_TruckCap		= INVALID_ITEM_TYPE,
ItemType:		item_BoaterHat		= INVALID_ITEM_TYPE,
ItemType:		item_BowlerHat		= INVALID_ITEM_TYPE,
// 140
ItemType:		item_PoliceCap		= INVALID_ITEM_TYPE,
ItemType:		item_TopHat			= INVALID_ITEM_TYPE,
ItemType:		item_Ammo9mm		= INVALID_ITEM_TYPE,
ItemType:		item_Ammo50			= INVALID_ITEM_TYPE,
ItemType:		item_AmmoBuck		= INVALID_ITEM_TYPE,
ItemType:		item_Ammo556		= INVALID_ITEM_TYPE,
ItemType:		item_Ammo357		= INVALID_ITEM_TYPE,
ItemType:		item_AmmoRocket		= INVALID_ITEM_TYPE,
ItemType:		item_MolotovEmpty	= INVALID_ITEM_TYPE,
ItemType:		item_Money			= INVALID_ITEM_TYPE,
// 150
ItemType:		item_PowerSupply	= INVALID_ITEM_TYPE,
ItemType:		item_StorageUnit	= INVALID_ITEM_TYPE,
ItemType:		item_Fluctuator		= INVALID_ITEM_TYPE,
ItemType:		item_IoUnit			= INVALID_ITEM_TYPE,
ItemType:		item_FluxCap		= INVALID_ITEM_TYPE,
ItemType:		item_DataInterface	= INVALID_ITEM_TYPE,
ItemType:		item_HackDevice		= INVALID_ITEM_TYPE,
ItemType:		item_PlantPot		= INVALID_ITEM_TYPE,
ItemType:		item_HerpDerp		= INVALID_ITEM_TYPE,
ItemType:		item_Parrot			= INVALID_ITEM_TYPE,
// 160
ItemType:		item_TntTripMine	= INVALID_ITEM_TYPE,
ItemType:		item_IedTimebomb	= INVALID_ITEM_TYPE,
ItemType:		item_IedProxMine	= INVALID_ITEM_TYPE,
ItemType:		item_IedTripMine	= INVALID_ITEM_TYPE,
ItemType:		item_IedPhoneBomb	= INVALID_ITEM_TYPE,
ItemType:		item_EmpTimebomb	= INVALID_ITEM_TYPE,
ItemType:		item_EmpProxMine	= INVALID_ITEM_TYPE,
ItemType:		item_EmpTripMine	= INVALID_ITEM_TYPE,
ItemType:		item_EmpPhoneBomb	= INVALID_ITEM_TYPE,
ItemType:		item_Gyroscope		= INVALID_ITEM_TYPE,
// 170
ItemType:		item_Motor			= INVALID_ITEM_TYPE,
ItemType:		item_StarterMotor	= INVALID_ITEM_TYPE,
ItemType:		item_FlareGun		= INVALID_ITEM_TYPE,
ItemType:		item_PetrolBomb		= INVALID_ITEM_TYPE,
ItemType:		item_CodePart		= INVALID_ITEM_TYPE,
ItemType:		item_LargeBackpack	= INVALID_ITEM_TYPE,
ItemType:		item_LocksmithKit	= INVALID_ITEM_TYPE,
ItemType:		item_XmasHat		= INVALID_ITEM_TYPE,
ItemType:		item_VehicleWeapon	= INVALID_ITEM_TYPE,
ItemType:		item_AdvancedKeypad	= INVALID_ITEM_TYPE,
// 180
ItemType:		item_Ammo9mmFMJ		= INVALID_ITEM_TYPE,
ItemType:		item_AmmoFlechette	= INVALID_ITEM_TYPE,
ItemType:		item_AmmoHomeBuck	= INVALID_ITEM_TYPE,
ItemType:		item_Ammo556Tracer	= INVALID_ITEM_TYPE,
ItemType:		item_Ammo556HP		= INVALID_ITEM_TYPE,
ItemType:		item_Ammo357Tracer	= INVALID_ITEM_TYPE,
ItemType:		item_Ammo762		= INVALID_ITEM_TYPE,
ItemType:		item_AK47Rifle		= INVALID_ITEM_TYPE,
ItemType:		item_M77RMRifle		= INVALID_ITEM_TYPE,
ItemType:		item_DogsBreath		= INVALID_ITEM_TYPE,
// 190
ItemType:		item_Ammo50BMG		= INVALID_ITEM_TYPE,
ItemType:		item_Ammo308		= INVALID_ITEM_TYPE,
ItemType:		item_Model70Rifle	= INVALID_ITEM_TYPE,
ItemType:		item_LenKnocksRifle	= INVALID_ITEM_TYPE,
ItemType:		item_Daypack		= INVALID_ITEM_TYPE,
ItemType:		item_MediumBag		= INVALID_ITEM_TYPE,
ItemType:		item_Rucksack		= INVALID_ITEM_TYPE,
ItemType:		item_SeedBag		= INVALID_ITEM_TYPE,
ItemType:		item_Note			= INVALID_ITEM_TYPE,
ItemType:		item_Tomato			= INVALID_ITEM_TYPE,
// 200
ItemType:		item_HeartShapedBox	= INVALID_ITEM_TYPE,
ItemType:		item_AntiSepBandage	= INVALID_ITEM_TYPE,
ItemType:		item_WoodLog		= INVALID_ITEM_TYPE,
ItemType:		item_Sledgehammer	= INVALID_ITEM_TYPE,
ItemType:		item_RawFish		= INVALID_ITEM_TYPE,
ItemType:		item_Spanner		= INVALID_ITEM_TYPE,
ItemType:		item_Suitcase		= INVALID_ITEM_TYPE,
ItemType:		item_OilCan			= INVALID_ITEM_TYPE,
ItemType:		item_RadioBox		= INVALID_ITEM_TYPE,
ItemType:		item_BigSword		= INVALID_ITEM_TYPE,
// 210
ItemType:		item_Microphone		= INVALID_ITEM_TYPE,
ItemType:		item_Spatula		= INVALID_ITEM_TYPE,
ItemType:		item_Pan			= INVALID_ITEM_TYPE,
ItemType:		item_Knife2			= INVALID_ITEM_TYPE,
ItemType:		item_Meat2			= INVALID_ITEM_TYPE,
ItemType:		item_FryingPan		= INVALID_ITEM_TYPE,
ItemType:		item_PizzaOnly		= INVALID_ITEM_TYPE,
ItemType:		item_BreadLoaf		= INVALID_ITEM_TYPE,
ItemType:		item_Banana			= INVALID_ITEM_TYPE,
ItemType:		item_Orange			= INVALID_ITEM_TYPE,
// 220
ItemType:		item_WheelLock		= INVALID_ITEM_TYPE,
ItemType:		item_RedApple		= INVALID_ITEM_TYPE,
ItemType:		item_Lemon			= INVALID_ITEM_TYPE,
ItemType:		item_PisschBox		= INVALID_ITEM_TYPE,
ItemType:		item_PizzaBox		= INVALID_ITEM_TYPE,
ItemType:		item_MilkBottle		= INVALID_ITEM_TYPE,
ItemType:		item_MilkCarton		= INVALID_ITEM_TYPE,
ItemType:		item_IceCream		= INVALID_ITEM_TYPE,
ItemType:		item_FishyFingers	= INVALID_ITEM_TYPE,
ItemType:		item_IceCreamBars	= INVALID_ITEM_TYPE,
// 230
ItemType:		item_AppleJuice		= INVALID_ITEM_TYPE,
ItemType:		item_OrangeJuice	= INVALID_ITEM_TYPE,
ItemType:		item_Cereal1		= INVALID_ITEM_TYPE,
ItemType:		item_Cereal2		= INVALID_ITEM_TYPE,
ItemType:		item_WrappedMeat	= INVALID_ITEM_TYPE,
ItemType:		item_Beanie			= INVALID_ITEM_TYPE,
ItemType:		item_StrawHat		= INVALID_ITEM_TYPE,
ItemType:		item_WitchesHat		= INVALID_ITEM_TYPE,
ItemType:		item_WeddingCake	= INVALID_ITEM_TYPE,
ItemType:		item_CaptainsCap	= INVALID_ITEM_TYPE,
// 240
ItemType:		item_SwatHelmet		= INVALID_ITEM_TYPE,
ItemType:		item_PizzaHat		= INVALID_ITEM_TYPE,
ItemType:		item_PussyMask		= INVALID_ITEM_TYPE,
ItemType:		item_BoxingGloves	= INVALID_ITEM_TYPE,
ItemType:		item_Briquettes		= INVALID_ITEM_TYPE,
ItemType:		item_DevilMask		= INVALID_ITEM_TYPE,
ItemType:		item_Cross			= INVALID_ITEM_TYPE,
ItemType:		item_RedPanel		= INVALID_ITEM_TYPE,
ItemType:		item_Fork			= INVALID_ITEM_TYPE,
ItemType:		item_Knife3			= INVALID_ITEM_TYPE,
// 250
ItemType:		item_Ketchup		= INVALID_ITEM_TYPE,
ItemType:		item_Mustard		= INVALID_ITEM_TYPE,
ItemType:		item_Boot			= INVALID_ITEM_TYPE,
ItemType:		item_Doormat		= INVALID_ITEM_TYPE,
ItemType:		item_CakeSlice		= INVALID_ITEM_TYPE,
ItemType:		item_Holdall		= INVALID_ITEM_TYPE,
ItemType:		item_GrnApple		= INVALID_ITEM_TYPE,
ItemType:		item_Wine1			= INVALID_ITEM_TYPE,
ItemType:		item_Wine2			= INVALID_ITEM_TYPE,
ItemType:		item_Wine3			= INVALID_ITEM_TYPE,
// 260
ItemType:		item_Whisky			= INVALID_ITEM_TYPE,
ItemType:		item_Champagne		= INVALID_ITEM_TYPE,
ItemType:		item_Ham			= INVALID_ITEM_TYPE,
ItemType:		item_Steak			= INVALID_ITEM_TYPE,
ItemType:		item_Bread			= INVALID_ITEM_TYPE,
ItemType:		item_Broom			= INVALID_ITEM_TYPE,
ItemType:		item_Keycard		= INVALID_ITEM_TYPE,
ItemType:		item_BurntLog		= INVALID_ITEM_TYPE,
ItemType:		item_Padlock		= INVALID_ITEM_TYPE,
ItemType:		item_OilDrum		= INVALID_ITEM_TYPE,
// 270
ItemType:		item_Canister		= INVALID_ITEM_TYPE,
ItemType:		item_ScrapMetal		= INVALID_ITEM_TYPE,
ItemType:		item_RefinedMetal	= INVALID_ITEM_TYPE,
ItemType:		item_Locator		= INVALID_ITEM_TYPE,
ItemType:		item_PlotPole		= INVALID_ITEM_TYPE,
ItemType:		item_ScrapMachine	= INVALID_ITEM_TYPE,
ItemType:		item_RefineMachine	= INVALID_ITEM_TYPE,
ItemType:		item_WaterMachine	= INVALID_ITEM_TYPE,
ItemType:		item_Workbench		= INVALID_ITEM_TYPE,
ItemType:		item_Radio			= INVALID_ITEM_TYPE,
// 280
ItemType:		item_Locker			= INVALID_ITEM_TYPE,
ItemType:		item_GearBox		= INVALID_ITEM_TYPE,
ItemType:		item_ToolBox		= INVALID_ITEM_TYPE,
ItemType:		item_MetalFrame		= INVALID_ITEM_TYPE,
ItemType:		item_LockBreaker	= INVALID_ITEM_TYPE,
ItemType:		item_PoliceHelm		= INVALID_ITEM_TYPE,
ItemType:		item_ControlBox		= INVALID_ITEM_TYPE,
ItemType:		item_Computer		= INVALID_ITEM_TYPE,
ItemType:		item_TallFrame		= INVALID_ITEM_TYPE,
ItemType:		item_RemoteControl	= INVALID_ITEM_TYPE,
// 290
ItemType:		item_Desk			= INVALID_ITEM_TYPE,
ItemType:		item_Table			= INVALID_ITEM_TYPE,
ItemType:		item_GunCase		= INVALID_ITEM_TYPE,
ItemType:		item_Cupboard		= INVALID_ITEM_TYPE,
ItemType:		item_Barstool		= INVALID_ITEM_TYPE,
ItemType:		item_SmallTable		= INVALID_ITEM_TYPE,
ItemType:		item_BandanaBlue	= INVALID_ITEM_TYPE,
ItemType:		item_BandanaGrey	= INVALID_ITEM_TYPE,
ItemType:		item_BandanaWhite	= INVALID_ITEM_TYPE,
ItemType:		item_BandanaPattern	= INVALID_ITEM_TYPE;


hook OnScriptInit() {
// 00
	item_NULL			= DefineItemType("NULL",				"NULL",				0,		1, .maxhitpoints = 0);
	item_Knuckles		= DefineItemType("Knuckle Duster",		"Knuckles",			331,	1,	90.0, .maxhitpoints = 1);
	item_GolfClub		= DefineItemType("Golf Club",			"GolfClub",			333,	3,	90.0, .maxhitpoints = 3);
	item_Baton			= DefineItemType("Baton",				"Baton",			334,	2,	90.0, .maxhitpoints = 2);
	item_Knife			= DefineItemType("Combat Knife",		"Knife",			335,	1,	90.0, .maxhitpoints = 1);
	item_Bat			= DefineItemType("Baseball Bat",		"Bat",				336,	3,	90.0, .maxhitpoints = 3);
	item_Spade			= DefineItemType("Spade",				"Spade",			337,	3,	90.0, .maxhitpoints = 3);
	item_PoolCue		= DefineItemType("Pool Cue",			"PoolCue",			338,	4,	90.0, .maxhitpoints = 4);
	item_Sword			= DefineItemType("Sword",				"Sword",			339,	4,	90.0, .maxhitpoints = 4);
	item_Chainsaw		= DefineItemType("Chainsaw",			"Chainsaw",			341,	5,	90.0, .maxhitpoints = 5);
// 10
	item_Dildo1			= DefineItemType("Dildo",				"Dildo1",			321,	1,	90.0, .maxhitpoints = 1);
	item_Dildo2			= DefineItemType("Dildo",				"Dildo2",			322,	1,	90.0, .maxhitpoints = 1);
	item_Dildo3			= DefineItemType("Dildo",				"Dildo3",			323,	1,	90.0, .maxhitpoints = 1);
	item_Dildo4			= DefineItemType("Dildo",				"Dildo4",			324,	1,	90.0, .maxhitpoints = 1);
	item_Flowers		= DefineItemType("Flowers",				"Flowers",			325,	2,	90.0, .maxhitpoints = 2);
	item_WalkingCane	= DefineItemType("Cane",				"WalkingCane",		326,	3,	90.0, .maxhitpoints = 3);
	item_Grenade		= DefineItemType("Grenade",				"Grenade",			342,	2,	90.0, .maxhitpoints = 2);
	item_Teargas		= DefineItemType("Teargas",				"Teargas",			343,	2,	90.0, .maxhitpoints = 2);
	item_Molotov		= DefineItemType("Molotov",				"Molotov",			344,	2,	90.0, .maxhitpoints = 2);
	item_NULL2			= DefineItemType("<null>",				"NULL2",			000,	1,	90.0, .maxhitpoints = 1);
// 20
	item_NULL3			= DefineItemType("<null>",				"NULL3",			000,	1,	90.0, .maxhitpoints = 1);
	item_NULL4			= DefineItemType("<null>",				"NULL4",			000,	1,	90.0, .maxhitpoints = 1);
	item_M9Pistol		= DefineItemType("M9",					"M9Pistol",			346,	1,	90.0, .maxhitpoints = 1);
	item_M9PistolSD		= DefineItemType("M9 SD",				"M9PistolSD",		347,	1,	90.0, .maxhitpoints = 1);
	item_DesertEagle	= DefineItemType("Desert Eagle",		"DesertEagle",		348,	1,	90.0, .maxhitpoints = 1);
	item_PumpShotgun	= DefineItemType("Shotgun",				"PumpShotgun",		349,	3,	90.0, .maxhitpoints = 3);
	item_Sawnoff		= DefineItemType("Sawnoff",				"Sawnoff",			350,	2,	90.0, .maxhitpoints = 2);
	item_Spas12			= DefineItemType("Spas 12",				"Spas12",			351,	4,	90.0, .maxhitpoints = 4);
	item_Mac10			= DefineItemType("Mac 10",				"Mac10",			352,	2,	90.0, .maxhitpoints = 2);
	item_MP5			= DefineItemType("MP5",					"MP5",				353,	4,	90.0, .maxhitpoints = 4);
// 30
	item_WASR3Rifle		= DefineItemType("WASR-3",				"WASR3Rifle",		355,	5,	90.0, .maxhitpoints = 5);
	item_M16Rifle		= DefineItemType("M16",					"M16Rifle",			356,	5,	90.0, .maxhitpoints = 5);
	item_Tec9			= DefineItemType("Tec 9",				"Tec9",				372,	2,	90.0, .maxhitpoints = 2);
	item_SemiAutoRifle	= DefineItemType("Rifle",				"SemiAutoRifle",	357,	5,	90.0, .maxhitpoints = 5);
	item_SniperRifle	= DefineItemType("Sniper",				"SniperRifle",		358,	5,	90.0, .maxhitpoints = 5);
	item_RocketLauncher	= DefineItemType("RPG",					"RocketLauncher",	359,	6,	90.0, .maxhitpoints = 6);
	item_Heatseeker		= DefineItemType("Heatseeker",			"Heatseeker",		360,	6,	90.0, .maxhitpoints = 6);
	item_Flamer			= DefineItemType("Flamer",				"Flamer",			361,	7,	90.0, .maxhitpoints = 7);
	item_Minigun		= DefineItemType("Minigun",				"Minigun",			362,	7,	90.0, .maxhitpoints = 7);
	item_RemoteBomb		= DefineItemType("Remote Bomb",			"RemoteBomb",		363,	2,	90.0, .maxhitpoints = 2);
// 40
	item_Detonator		= DefineItemType("Detonator",			"Detonator",		364,	2,	90.0, .maxhitpoints = 2);
	item_SprayPaint		= DefineItemType("Spray Paint",			"SprayPaint",		365,	1,	90.0, .maxhitpoints = 1);
	item_Extinguisher	= DefineItemType("Extinguisher",		"Extinguisher",		366,	4,	90.0, .maxhitpoints = 4);
	item_Camera			= DefineItemType("Camera",				"Camera",			367,	2,	90.0, .maxhitpoints = 2);
	item_NightVision	= DefineItemType("Night Vision",		"NightVision",		000,	2,	90.0, .maxhitpoints = 2);
	item_ThermalVision	= DefineItemType("Thermal Vision",		"ThermalVision",	000,	2,	90.0, .maxhitpoints = 2);
	item_Parachute		= DefineItemType("Parachute",			"Parachute",		371,	6,	90.0, 0.0, 0.0,			0.0,	0.350542, 0.017385, 0.060469, 0.000000, 260.845062, 0.000000, .maxhitpoints = 6);
	item_Medkit			= DefineItemType("Medkit",				"Medkit",			11736,	1,	0.0, 0.0, 0.0,			0.004,	0.197999, 0.038000, 0.021000,  79.700012, 0.000000, 90.899978, .maxhitpoints = 1);
	item_HardDrive		= DefineItemType("Hard Drive",			"HardDrive",		328,	1,	90.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_Key			= DefineItemType("Key",					"Key",				11746,	1,	90.0, 0.0, 0.0,			0.08,	.maxhitpoints = 1);
// 50
	item_FireworkBox	= DefineItemType("Fireworks",			"FireworkBox",		2039,	2,	0.0, 0.0, 0.0,			0.0,	0.096996, 0.044811, 0.035688, 4.759557, 255.625167, 0.000000, .maxhitpoints = 2);
	item_FireLighter	= DefineItemType("Lighter",				"FireLighter",		19998,	1,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_Timer			= DefineItemType("Timer Device",		"Timer",			2922,	2,	90.0, 0.0, 0.0,			0.0,	0.231612, 0.050027, 0.017069, 0.000000, 343.020019, 180.000000, .maxhitpoints = 2);
	item_Explosive		= DefineItemType("TNT",					"Explosive",		1576,	2,	0.0, 0.0, 0.0,			0.0,	0.269091, 0.166367, 0.000000, 90.000000, 0.000000, 0.000000, .maxhitpoints = 2);
	item_TntTimebomb	= DefineItemType("Timed TNT",			"TntTimebomb",		1252,	2,	270.0, 0.0, 0.0,		0.0,	.maxhitpoints = 2);
	item_Battery		= DefineItemType("Battery",				"Battery",			1579,	2,	0.0, 0.0, 0.0,			0.0,	0.269091, 0.166367, 0.000000, 90.000000, 0.000000, 0.000000, .maxhitpoints = 2);
	item_Fusebox		= DefineItemType("Fuse Box",			"Fusebox",			328,	2,	90.0, 0.0, 0.0,			0.0,	.maxhitpoints = 2);
	item_Bottle			= DefineItemType("Bottle",				"Bottle",			1543,	1,	0.0, 0.0, 0.0,			0.0,	0.060376, 0.032063, -0.204802, 0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_Sign			= DefineItemType("Sign",				"Sign",				19471,	6,	0.0, 0.0, 270.0,		0.0,	.longpickup = true, .maxhitpoints = 6);
	item_Armour			= DefineItemType("Armour",				"Armour",			19515,	4,	90.0, 0.0, 0.0,			0.0,	0.300333, -0.090105, 0.000000, 0.000000, 0.000000, 180.000000, .maxhitpoints = 4);
// 60
	item_Bandage		= DefineItemType("Dirty Bandage",		"Bandage",			11747,	2,	90.0, 0.0, 0.0,			0.0,	0.076999, 0.059000, 0.000000,  2.799999, -5.600000, 0.000000, .maxhitpoints = 2);
	item_FishRod		= DefineItemType("Fishing Rod",			"FishRod",			18632,	6,	90.0, 0.0, 0.0,			0.0,	0.091496, 0.019614, 0.000000, 185.619995, 354.958374, 0.000000, .maxhitpoints = 6);
	item_Wrench			= DefineItemType("Wrench",				"Wrench",			18633,	2,	0.0, 90.0, 0.0,			0.0,	0.084695, -0.009181, 0.152275, 98.865089, 270.085449, 0.000000, .maxhitpoints = 2);
	item_Crowbar		= DefineItemType("Crowbar",				"Crowbar",			18634,	2,	0.0, 90.0, 0.0,			0.0,	0.066177, 0.011153, 0.038410, 97.289527, 270.962554, 1.114514, .maxhitpoints = 2);
	item_Hammer			= DefineItemType("Hammer",				"Hammer",			18635,	2,	270.0, 0.0, 0.0,		0.01,	0.000000, -0.008230, 0.000000, 6.428617, 0.000000, 0.000000, .maxhitpoints = 2);
	item_Shield			= DefineItemType("Shield",				"Shield",			18637,	8,	0.0, 0.0, 0.0,			0.0,	-0.262389, 0.016478, -0.151046, 103.597534, 6.474381, 38.321765, .maxhitpoints = 8);
	item_Flashlight		= DefineItemType("Flashlight",			"Flashlight",		18641,	2,	90.0, 0.0, 0.0,			0.0,	0.061910, 0.022700, 0.039052, 190.938354, 0.000000, 0.000000, .maxhitpoints = 2);
	item_StunGun		= DefineItemType("Stun Gun",			"StunGun",			18642,	1,	90.0, 0.0, 0.0,			0.0,	0.079878, 0.014009, 0.029525, 180.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_LaserPoint		= DefineItemType("Laser Pointer",		"LaserPoint",		18643,	1,	0.0, 0.0, 90.0,			0.0,	0.066244, 0.010838, -0.000024, 6.443027, 287.441467, 0.000000, .maxhitpoints = 1);
	item_Screwdriver	= DefineItemType("Screwdriver",			"Screwdriver",		18644,	1,	90.0, 0.0, 0.0,			0.0,	0.099341, 0.021018, 0.009145, 193.644195, 0.000000, 0.000000, .maxhitpoints = 1);
// 70
	item_MobilePhone	= DefineItemType("Mobile Phone",		"MobilePhone",		18865,	1,	0.0, 0.0, 0.0,			0.0,	0.103904, -0.003697, -0.015173, 94.655189, 184.031860, 0.000000, .maxhitpoints = 1);
	item_Pager			= DefineItemType("Pager",				"Pager",			18875,	1,	0.0, 0.0, 0.0,			0.0,	0.097277, 0.027625, 0.013023, 90.819244, 191.427993, 0.000000, .maxhitpoints = 1);
	item_Rake			= DefineItemType("Rake",				"Rake",				18890,	6,	90.0, 0.0, 0.0,			0.0,	-0.002599, 0.003984, 0.026356, 190.231231, 0.222518, 271.565185, .maxhitpoints = 6);
	item_HotDog			= DefineItemType("Hotdog",				"HotDog",			19346,	1,	0.0, 0.0, 0.0,			0.0,	0.088718, 0.035828, 0.008570, 272.851745, 354.704772, 9.342185, .maxhitpoints = 1);
	item_EasterEgg		= DefineItemType("Easter Egg",			"EasterEgg",		19345,	3,	0.0, 0.0, 0.0,			0.0,	0.000000, 0.000000, 0.000000, 0.000000, 90.000000, 0.000000, .maxhitpoints = 3);
	item_Cane			= DefineItemType("Cane",				"Cane",				19348,	3,	270.0, 0.0, 0.0,		0.0,	0.041865, 0.022883, -0.079726, 4.967216, 10.411237, 0.000000, .maxhitpoints = 3);
	item_HandCuffs		= DefineItemType("Handcuffs",			"HandCuffs",		19418,	1,	270.0, 0.0, 0.0,		0.0,	0.077635, 0.011612, 0.000000, 0.000000, 90.000000, 0.000000, .maxhitpoints = 1);
	item_Bucket			= DefineItemType("Bucket",				"Bucket",			19468,	2,	0.0, 0.0, 0.0,			0.0,	0.293691, -0.074108, 0.020810, 148.961685, 280.067260, 151.782791, .maxhitpoints = 2);
	item_GasMask		= DefineItemType("Gas Mask",			"GasMask",			19472,	1,	180.0, 0.0, 0.0,		0.0,	0.062216, 0.055396, 0.001138, 90.000000, 0.000000, 180.000000, .maxhitpoints = 1);
	item_Flag			= DefineItemType("Flag",				"Flag",				2993,	3,	0.0, 0.0, 0.0,			0.0,	0.045789, 0.026306, -0.078802, 8.777217, 0.272155, 0.000000, .maxhitpoints = 3);
// 80
	item_DoctorBag		= DefineItemType("Doctor's Bag",		"DoctorBag",		11738,	3,	0.0, 0.0, 0.0,			0.0046,	0.265000, 0.029000, 0.041000,  0.000000, -99.100021, 0.000000, .maxhitpoints = 3);
	item_Backpack		= DefineItemType("Backpack",			"Backpack",			3026,	4,	270.0, 0.0, 90.0,		0.0,	0.470918, 0.150153, 0.055384, 181.319580, 7.513789, 163.436065, .longpickup = true, .maxhitpoints = 4);
	item_Satchel		= DefineItemType("Small Bag",			"Satchel",			363,	2,	270.0, 0.0, 0.0,		0.0,	0.052853, 0.034967, -0.177413, 0.000000, 261.397491, 349.759826, .longpickup = true, .maxhitpoints = 2);
	item_Wheel			= DefineItemType("Wheel",				"Wheel",			1079,	5,	0.0, 0.0, 90.0,			0.436,	-0.098016, 0.356168, -0.309851, 258.455596, 346.618103, 354.313049, true, .maxhitpoints = 5);
	item_MotionSense	= DefineItemType("Motion Sensor",		"MotionSense",		327,	1,	0.0, 0.0, 0.0,			0.0,	0.008151, 0.012682, -0.050635, 0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_Accelerometer	= DefineItemType("Accelerometer",		"Accelerometer",	327,	1,	0.0, 0.0, 0.0,			0.0,	0.008151, 0.012682, -0.050635, 0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_TntProxMine	= DefineItemType("Proximity TNT",		"TntProxMine",		1576,	2,	0.0, 0.0, 0.0,			0.0,	0.269091, 0.166367, 0.000000, 90.000000, 0.000000, 0.000000, .maxhitpoints = 2);
	item_IedBomb		= DefineItemType("IED",					"IedBomb",			2033,	2,	0.0, 0.0, 0.0,			0.0,	0.100000, 0.055999, 0.000000,  -86.099967, -112.099975, 100.099891, .maxhitpoints = 2);
	item_Pizza			= DefineItemType("Pizza",				"Pizza",			1582,	2,	0.0, 0.0, 0.0,			0.0,	0.320344, 0.064041, 0.168296, 92.941909, 358.492523, 14.915378, .maxhitpoints = 2);
	item_Burger			= DefineItemType("Burger",				"Burger",			2703,	1,	-76.0, 257.0, -11.0,	0.0,	0.066739, 0.041782, 0.026828, 3.703052, 3.163064, 6.946474, .maxhitpoints = 1);
// 90
	item_BurgerBox		= DefineItemType("Burger",				"BurgerBox",		2768,	1,	0.0, 0.0, 0.0,			0.0,	0.107883, 0.093265, 0.029676, 91.010627, 7.522015, 0.000000, .maxhitpoints = 1);
	item_Taco			= DefineItemType("Taco",				"Taco",				2769,	1,	0.0, 0.0, 0.0,			0.0,	0.069803, 0.057707, 0.039241, 0.000000, 78.877342, 0.000000, .maxhitpoints = 1);
	item_GasCan			= DefineItemType("Petrol Can",			"GasCan",			1650,	3,	0.0, 0.0, 0.0,			0.27,	0.143402, 0.027548, 0.063652, 0.000000, 253.648208, 0.000000, .maxhitpoints = 3);
	item_Clothes		= DefineItemType("Clothes",				"Clothes",			2891,	2,	0.0, 0.0, 0.0,			0.0,	0.269091, 0.166367, 0.000000, 90.000000, 0.000000, 0.000000, .maxhitpoints = 2);
	item_HelmArmy		= DefineItemType("Army Helmet",			"HelmArmy",			19106,	2,	345.0, 270.0, 0.0,		0.045,	0.184999, -0.007999, 0.046999, 94.199989, 22.700027, 4.799994, .maxhitpoints = 2);
	item_MediumBox		= DefineItemType("Medium Box",			"MediumBox",		3014,	5,	0.0, 0.0, 0.0,			0.1844,	-0.027872, 0.145617, -0.246524, 243.789840, 347.397491, 349.931610, true, .longpickup = true, .maxhitpoints = 5);
	item_SmallBox		= DefineItemType("Small Box",			"SmallBox",			2969,	4,	0.0, 0.0, 0.0,			0.0,	0.114177, 0.089762, -0.173014, 247.160079, 354.746368, 79.219100, true, .longpickup = true, .maxhitpoints = 4);
	item_LargeBox		= DefineItemType("Large Box",			"LargeBox",			1271,	6,	0.0, 0.0, 0.0,			0.3112,	0.050000, 0.334999, -0.327000,  -23.900018, -10.200002, 11.799987, true, .longpickup = true, .maxhitpoints = 6);
	item_HockeyMask		= DefineItemType("Hockey Mask",			"HockeyMask",		19036,	1,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 1);
	item_Meat			= DefineItemType("Meat",				"Meat",				2804,	3,	0.0, 0.0, 0.0,			0.0,	-0.051398, 0.017334, 0.189188, 270.495391, 353.340423, 167.069869, .maxhitpoints = 3);
// 100
	item_DeadLeg		= DefineItemType("Leg",					"DeadLeg",			2905,	4,	0.0, 0.0, 0.0,			0.0,	0.147815, 0.052444, -0.164205, 253.163970, 358.857666, 167.069869, true, .maxhitpoints = 4);
	item_Torso			= DefineItemType("Torso",				"Torso",			2907,	6,	0.0, 0.0, 270.0,		0.0,	0.087207, 0.093263, -0.280867, 253.355865, 355.971557, 175.203552, true, .longpickup = true, .maxhitpoints = 6);
	item_LongPlank		= DefineItemType("Plank",				"LongPlank",		2937,	9,	0.0, 0.0, 0.0,			0.0,	0.141491, 0.002142, -0.190920, 248.561920, 350.667724, 175.203552, true, .maxhitpoints = 9);
	item_GreenGloop		= DefineItemType("Unknown",				"GreenGloop",		2976,	3,	0.0, 0.0, 0.0,			0.0,	0.063387, 0.013771, -0.595982, 341.793945, 352.972686, 226.892105, true, .maxhitpoints = 3);
	item_Capsule		= DefineItemType("Capsule",				"Capsule",			3082,	3,	0.0, 0.0, 0.0,			0.0,	0.096439, 0.034642, -0.313377, 341.793945, 348.492706, 240.265777, true, .longpickup = true, .maxhitpoints = 3);
	item_RadioPole		= DefineItemType("Receiver",			"RadioPole",		3221,	3,	0.0, 0.0, 0.0,			0.0,	0.081356, 0.034642, -0.167247, 0.000000, 0.000000, 240.265777, .maxhitpoints = 3);
	item_SignShot		= DefineItemType("Sign",				"SignShot",			3265,	3,	0.0, 0.0, 0.0,			0.0,	0.081356, 0.034642, -0.167247, 0.000000, 0.000000, 240.265777, .maxhitpoints = 3);
	item_Mailbox		= DefineItemType("Mailbox",				"Mailbox",			3407,	3,	0.0, 0.0, 0.0,			0.0,	0.081356, 0.034642, -0.167247, 0.000000, 0.000000, 240.265777, .maxhitpoints = 3);
	item_Pumpkin		= DefineItemType("Pumpkin",				"Pumpkin",			19320,	5,	0.0, 0.0, 0.0,			0.3,	0.105948, 0.279332, -0.253927, 246.858016, 0.000000, 0.000000, true, .maxhitpoints = 5);
	item_Nailbat		= DefineItemType("Nailbat",				"Nailbat",			2045,	3,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 3);
// 110
	item_ZorroMask		= DefineItemType("Zorro Mask",			"ZorroMask",		18974,	1,	0.0, 0.0, 0.0,			0.0,	0.193932, 0.050861, 0.017257, 90.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_Barbecue		= DefineItemType("BBQ",					"Barbecue",			19831,	6,	0.0, 0.0, 0.0,			-0.0313,0.321000, -0.611000, 0.084999,  66.000007, -163.699981, 80.899917, true, .maxhitpoints = 6);
	item_Headlight		= DefineItemType("Headlight",			"Headlight",		19280,	1,	90.0, 0.0, 0.0,			0.0,	0.107282, 0.051477, 0.023807, 0.000000, 259.073913, 351.287475, .maxhitpoints = 1);
	item_Pills			= DefineItemType("Pills",				"Pills",			2709,	1,	0.0, 0.0, 0.0,			0.09,	0.044038, 0.082106, 0.000000, 0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_AutoInjec		= DefineItemType("Injector",			"AutoInjec",		2711,	1,	90.0, 0.0, 0.0,			0.028,	0.145485, 0.020127, 0.034870, 0.000000, 260.512817, 349.967254, .maxhitpoints = 1);
	item_BurgerBag		= DefineItemType("Burger",				"BurgerBag",		2663,	2,	0.0, 0.0, 0.0,			0.205,	0.320356, 0.042146, 0.049817, 0.000000, 260.512817, 349.967254, .maxhitpoints = 2);
	item_CanDrink		= DefineItemType("Can",					"CanDrink",			2601,	1,	0.0, 0.0, 0.0,			0.054,	0.064848, 0.059404, 0.017578, 0.000000, 359.136199, 30.178396, .maxhitpoints = 1);
	item_Detergent		= DefineItemType("Detergent",			"Detergent",		1644,	1,	0.0, 0.0, 0.0,			0.1,	0.081913, 0.047686, -0.026389, 95.526962, 0.546049, 358.890563, .maxhitpoints = 1);
	item_Dice			= DefineItemType("Dice",				"Dice",				1851,	5,	0.0, 0.0, 0.0,			0.136,	0.031958, 0.131180, -0.214385, 69.012298, 16.103448, 10.308629, true, .maxhitpoints = 5);
	item_Dynamite		= DefineItemType("Dynamite",			"Dynamite",			1654,	2,									.maxhitpoints = 2);
// 120
	item_Door			= DefineItemType("Metal Door",			"Door",				18553,	9,	0.0, 90.0, 90.0,		0.0,	0.313428, -0.507642, -1.340901, 336.984893, 348.837493, 113.141563, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 2);
	item_MetPanel		= DefineItemType("Metal Panel",			"MetPanel",			1965,	10,	0.0, 90.0, 0.0,			0.0,	0.070050, 0.008440, -0.180277, 338.515014, 349.801025, 33.250347, true, .buttonz = ITEM_FLOOR_OFFSET / 3, .maxhitpoints = 5);
	item_MetalGate		= DefineItemType("Metal Gate",			"MetalGate",		19303,	10,	270.0, 0.0, 0.0,		0.0,	0.057177, 0.073761, -0.299014,  -19.439863, -10.153647, 105.119079, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 4);
	item_CrateDoor		= DefineItemType("Crate Door",			"CrateDoor",		3062,	9,	90.0, 90.0, 0.0,		0.0,	0.150177, -0.097238, -0.299014,  -19.439863, -10.153647, 105.119079, true, .buttonz = ITEM_FLOOR_OFFSET / 3, .maxhitpoints = 5);
	item_CorPanel		= DefineItemType("Corrugated Metal",	"CorPanel",			2904,	10,	90.0, 90.0, 0.0,		0.0,	-0.365094, 1.004213, -0.665850, 337.887634, 172.861953, 68.495330, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 6);
	item_ShipDoor		= DefineItemType("Ship Door",			"ShipDoor",			2944,	10,	180.0, 90.0, 0.0,		0.0,	0.134831, -0.039784, -0.298796, 337.887634, 172.861953, 162.198867, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 9);
	item_InsulDoor		= DefineItemType("Insulated Doorway",	"InsulDoor",		19398,	10,	0.0, 90.0, 90.0,		0.0,	-0.087715, 0.483874, 1.109397, 337.887634, 172.861953, 162.198867, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 7);
	item_InsulPanel		= DefineItemType("Insulated Panel",		"InsulPanel",		19371,	8,	0.0, 90.0, 90.0,		0.0,	-0.106182, 0.534724, -0.363847, 278.598419, 68.350570, 57.954662, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 7);
	item_SmallPanel		= DefineItemType("Small Metal Panel",	"SmallPanel",		19843,	11,	0.0, 0.0, 0.0,			0.0,	-0.068822, 0.989761, -0.620014,  -114.639907, -10.153647, 170.419097, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 5);
	item_WoodPanel		= DefineItemType("Wood Ramp",			"WoodPanel",		5153,	11,	360.0, 23.537, 0.0,		0.0,	-0.342762, 0.908910, -0.453703, 296.326019, 46.126548, 226.118209, true, .buttonz = ITEM_FLOOR_OFFSET / 2, .maxhitpoints = 7);
// 130
	item_Flare			= DefineItemType("Flare",				"Flare",			345,	2,									.maxhitpoints = 2);
	item_TntPhoneBomb	= DefineItemType("Phone Remote TNT",	"TntPhoneBomb",		1576,	2,	0.0, 0.0, 0.0,			0.0,	0.269091, 0.166367, 0.000000, 90.000000, 0.000000, 0.000000, .maxhitpoints = 2);
	item_ParaBag		= DefineItemType("Parachute Bag",		"ParaBag",			371,	6,	90.0, 0.0, 0.0,			0.0,	0.350542, 0.017385, 0.060469, 0.000000, 260.845062, 0.000000, .longpickup = true, .maxhitpoints = 6);
	item_Keypad			= DefineItemType("Keypad",				"Keypad",			19273,	2,	270.0, 0.0, 0.0,		0.0,	0.198234, 0.101531, 0.095477, 0.000000, 343.020019, 0.000000, .maxhitpoints = 2);
	item_TentPack		= DefineItemType("Tent Pack",			"TentPack",			1279,	6,	0.0, 0.0, 0.0,			0.0,	0.106261, 0.004634, -0.144552, 246.614654, 345.892211, 258.267395, true, .maxhitpoints = 6);
	item_Campfire		= DefineItemType("Campfire",			"Campfire",			19632,	5,	0.0, 0.0, 0.0,			0.0,	0.106261, 0.004634, -0.144552, 246.614654, 345.892211, 258.267395, true, .maxhitpoints = 5);
	item_CowboyHat		= DefineItemType("Cowboy Hat",			"CowboyHat",		18962,	1,	0.0, 270.0, 0.0,		0.0427,	0.232999, 0.032000, 0.016000, 0.000000, 2.700027, -67.300010, .maxhitpoints = 1);
	item_TruckCap		= DefineItemType("Trucker Cap",			"TruckCap",			18961,	1,	0.0, 0.0, 0.0,			0.01,	0.225000, 0.034000, 0.014000, 81.799942, 7.699998, 179.999954, .maxhitpoints = 1);
	item_BoaterHat		= DefineItemType("Boater Hat",			"BoaterHat",		18946,	1,	-12.18, 268.14, 0.0,	0.318,	0.225000, 0.034000, 0.014000, 81.799942, 7.699998, 179.999954, .maxhitpoints = 1);
	item_BowlerHat		= DefineItemType("Bowler Hat",			"BowlerHat",		18947,	1,	-12.18, 268.14, 0.0,	0.01,	0.225000, 0.034000, 0.014000, 81.799942, 7.699998, 179.999954, .maxhitpoints = 1);
//140
	item_PoliceCap		= DefineItemType("Police Cap",			"PoliceCap",		18636,	1,	0.0, 0.0, 0.0,			0.05,	0.225000, 0.034000, 0.014000, 81.799942, 7.699998, 179.999954, .maxhitpoints = 1);
	item_TopHat			= DefineItemType("Top Hat",				"TopHat",			19352,	2,	0.0, 0.0, 0.0,			-0.023,	0.225000, 0.034000, 0.014000, 81.799942, 7.699998, 179.999954, .maxhitpoints = 2);
	item_Ammo9mm		= DefineItemType("9mm Rounds",			"Ammo9mm",			2037,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_Ammo50			= DefineItemType(".50 Rounds",			"Ammo50",			2037,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_AmmoBuck		= DefineItemType("Shotgun Shells",		"AmmoBuck",			2038,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_Ammo556		= DefineItemType("5.56 Rounds",			"Ammo556",			2040,	3,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 3);
	item_Ammo357		= DefineItemType(".357 Rounds",			"Ammo357",			2039,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_AmmoRocket		= DefineItemType("Rockets",				"AmmoRocket",		3016,	4,	0.0, 0.0, 0.0,			0.0,	0.081998, 0.081005, -0.195033, 247.160079, 336.014343, 347.379638, true, .maxhitpoints = 4);
	item_MolotovEmpty	= DefineItemType("Empty Molotov",		"MolotovEmpty",		344,	1,	-4.0, 0.0, 0.0,			0.1728,	0.000000, -0.004999, 0.000000,  0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_Money			= DefineItemType("Pre-War Money",		"Money",			1212,	1,	0.0, 0.0, 0.0,			0.0,	0.133999, 0.022000, 0.018000,  -90.700004, -11.199998, -101.600013, .maxhitpoints = 1);
// 150
	item_PowerSupply	= DefineItemType("Power Supply",		"PowerSupply",		3016,	1,	0.0, 0.0, 0.0,			0.0,	0.255000, -0.054000, 0.032000, -87.499984, -7.599999, -7.999998, .maxhitpoints = 1);
	item_StorageUnit	= DefineItemType("Storage Unit",		"StorageUnit",		328,	1,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_Fluctuator		= DefineItemType("Fluctuator Unit",		"Fluctuator",		343,	1,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_IoUnit			= DefineItemType("I/O Unit",			"IoUnit",			19273,	1,	270.0, 0.0, 0.0,		0.0,	0.198234, 0.101531, 0.095477, 0.000000, 343.020019, 0.000000, .maxhitpoints = 1);
	item_FluxCap		= DefineItemType("Flux Capacitor",		"FluxCap",			343,	1,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_DataInterface	= DefineItemType("Data Interface",		"DataInterface",	19273,	1,	270.0, 0.0, 0.0,		0.0,	0.198234, 0.101531, 0.095477, 0.000000, 343.020019, 0.000000, .maxhitpoints = 1);
	item_HackDevice		= DefineItemType("Hack Interface",		"HackDevice",		364,	1,	0.0, 0.0, 0.0,			0.0,	0.134000, 0.080000, -0.037000,  84.299949, 3.399998, 9.400002, .maxhitpoints = 1);
	item_PlantPot		= DefineItemType("Plant Pot",			"PlantPot",			2203,	4,	0.0, 0.0, 0.0,			0.138,	-0.027872, 0.145617, -0.246524, 243.789840, 347.397491, 349.931610, true, .longpickup = true, .maxhitpoints = 4);
	item_HerpDerp		= DefineItemType("Derpification Unit",	"HerpDerp",			19513,	1,	0.0, 0.0, 0.0,			0.0,	0.103904, -0.003697, -0.015173, 94.655189, 184.031860, 0.000000, .maxhitpoints = 1);
	item_Parrot			= DefineItemType("Sebastian",			"Parrot",			19078,	2,	0.0, 0.0, 0.0,			0.0,	0.131000, 0.021000, 0.005999,  -86.000091, 6.700000, -106.300018, .maxhitpoints = 2);
// 160
	item_TntTripMine	= DefineItemType("Trip Mine TNT",		"TntTripMine",		1576,	2,	0.0, 0.0, 0.0,			0.0,	0.269091, 0.166367, 0.000000, 90.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_IedTimebomb	= DefineItemType("Timed IED",			"IedTimebomb",		2033,	2,	0.0, 0.0, 0.0,			0.0,	0.100000, 0.055999, 0.000000,  -86.099967, -112.099975, 100.099891, .maxhitpoints = 1);
	item_IedProxMine	= DefineItemType("Proximity IED",		"IedProxMine",		2033,	2,	0.0, 0.0, 0.0,			0.0,	0.100000, 0.055999, 0.000000,  -86.099967, -112.099975, 100.099891, .maxhitpoints = 1);
	item_IedTripMine	= DefineItemType("Trip Mine IED",		"IedTripMine",		2033,	2,	0.0, 0.0, 0.0,			0.0,	0.100000, 0.055999, 0.000000,  -86.099967, -112.099975, 100.099891, .maxhitpoints = 1);
	item_IedPhoneBomb	= DefineItemType("Phone Remote IED",	"IedPhoneBomb",		2033,	2,	0.0, 0.0, 0.0,			0.0,	0.100000, 0.055999, 0.000000,  -86.099967, -112.099975, 100.099891, .maxhitpoints = 1);
	item_EmpTimebomb	= DefineItemType("Timed EMP",			"EmpTimebomb",		343,	2,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_EmpProxMine	= DefineItemType("Proximity EMP",		"EmpProxMine",		343,	2,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_EmpTripMine	= DefineItemType("Trip Mine EMP",		"EmpTripMine",		343,	2,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_EmpPhoneBomb	= DefineItemType("Phone Remote EMP",	"EmpPhoneBomb",		343,	2,	0.0, 0.0, 0.0,			0.0,	.maxhitpoints = 1);
	item_Gyroscope		= DefineItemType("Gyroscope Unit",		"Gyroscope",		1945,	1,	0.0, 0.0, 0.0,			0.0,	0.180000, 0.085000, 0.009000,  -86.099967, -112.099975, 92.699890, .maxhitpoints = 1);
// 170
	item_Motor			= DefineItemType("Motor",				"Motor",			2006,	2,	0.0, 0.0, 0.0,			0.0,	0.129999, 0.087999, 0.009000,  -86.099967, -112.099975, 92.699890, .maxhitpoints = 2);
	item_StarterMotor	= DefineItemType("Starter Motor",		"StarterMotor",		2006,	2,	0.0, 0.0, 0.0,			0.0,	0.129999, 0.087999, 0.009000,  -86.099967, -112.099975, 92.699890, .maxhitpoints = 2);
	item_FlareGun		= DefineItemType("Flare Gun",			"FlareGun",			2034,	2,	0.0, 0.0, 0.0,			0.0,	0.176000, 0.020000, 0.039999,  89.199989, -0.900000, 1.099991, .maxhitpoints = 2);
	item_PetrolBomb		= DefineItemType("Petrol Bomb",			"PetrolBomb",		1650,	3,	0.0, 0.0, 0.0,			0.27,	0.143402, 0.027548, 0.063652, 0.000000, 253.648208, 0.000000, .maxhitpoints = 3);
	item_CodePart		= DefineItemType("Code",				"CodePart",			1898,	1,	90.0, 0.0, 0.0,			0.02,	0.086999, 0.017999, 0.075999,  0.000000, 0.000000, 100.700019, .maxhitpoints = 1);
	item_LargeBackpack	= DefineItemType("Large Backpack",		"LargeBackpack",	3026,	5,	270.0, 0.0, 90.0,		0.0,	0.470918, 0.150153, 0.055384, 181.319580, 7.513789, 163.436065, false, 0xFFF4A460, .longpickup = true, .maxhitpoints = 5);
	item_LocksmithKit	= DefineItemType("Locksmith Kit",		"LocksmithKit",		1210,	3,	0.0, 0.0, 90.0,			0.0,	0.285915, 0.078406, -0.009429, 0.000000, 270.000000, 0.000000, false, 0xFFF4A460, .maxhitpoints = 3);
	item_XmasHat		= DefineItemType("Christmas Hat",		"XmasHat",			19066,	1,	0.0, 0.0, 0.0,			0.0,	0.135000, -0.018001, -0.002000,  90.000000, 174.500061, 9.600001, .maxhitpoints = 1);
	item_VehicleWeapon	= DefineItemType("VEHICLE_WEAPON",		"VehicleWeapon",	356,	99,	90.0,							.maxhitpoints = 99);
	item_AdvancedKeypad	= DefineItemType("Advanced Keypad",		"AdvancedKeypad",	19273,	2,	270.0, 0.0, 0.0,		0.0,	0.198234, 0.101531, 0.095477, 0.000000, 343.020019, 0.000000, .maxhitpoints = 2);
// 180
	item_Ammo9mmFMJ		= DefineItemType("9mm Rounds",			"Ammo9mmFMJ",		2037,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_AmmoFlechette	= DefineItemType("Shotgun Shells",		"AmmoFlechette",	2038,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_AmmoHomeBuck	= DefineItemType("Shotgun Shells",		"AmmoHomeBuck",		2038,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_Ammo556Tracer	= DefineItemType("5.56 Rounds",			"Ammo556Tracer",	2040,	3,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 3);
	item_Ammo556HP		= DefineItemType("5.56 Rounds",			"Ammo556HP",		2040,	3,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 3);
	item_Ammo357Tracer	= DefineItemType(".357 Rounds",			"Ammo357Tracer",	2039,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_Ammo762		= DefineItemType("7.62 Rounds",			"Ammo762",			2040,	3,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 3);
	item_AK47Rifle		= DefineItemType("AK-47",				"AK47Rifle",		355,	5,	90.0,							.maxhitpoints = 5);
	item_M77RMRifle		= DefineItemType("M77-RM",				"M77RMRifle",		357,	5,	90.0,							.maxhitpoints = 5);
	item_DogsBreath		= DefineItemType("Dog's Breath",		"DogsBreath",		2034,	2,	0.0, 0.0, 0.0,			0.0,	0.176000, 0.020000, 0.039999,  89.199989, -0.900000, 1.099991, .maxhitpoints = 2);
// 190
	item_Ammo50BMG		= DefineItemType(".50 Rounds",			"Ammo50BMG",		2037,	2,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 2);
	item_Ammo308		= DefineItemType(".308 Rounds",			"Ammo308",			2039,	1,	0.0, 0.0, 0.0,			0.082,	0.221075, 0.067746, 0.037494, 87.375968, 305.182189, 5.691741, .maxhitpoints = 1);
	item_Model70Rifle	= DefineItemType("Model 70",			"Model70Rifle",		358,	5,	90.0,							.maxhitpoints = 5);
	item_LenKnocksRifle	= DefineItemType("The Len-Knocks",		"LenKnocksRifle",	358,	5,	90.0,							.maxhitpoints = 5);
	item_Daypack		= DefineItemType("Daypack",				"Daypack",			363,	3,	270.0, 0.0, 0.0,		0.0,	0.052853, 0.034967, -0.177413, 0.000000, 261.397491, 349.759826, .longpickup = true, .maxhitpoints = 3);
	item_MediumBag		= DefineItemType("Medium Bag",			"MediumBag",		3026,	4,	270.0, 0.0, 90.0,		0.0,	0.470918, 0.150153, 0.055384, 181.319580, 7.513789, 163.436065, false, 0xFFFFFF00, .longpickup = true, .maxhitpoints = 4);
	item_Rucksack		= DefineItemType("Travel Rucksack",		"Rucksack",			19559,	5,	91.0, -4.0, 0.0,		0.16,	0.350542, 0.017385, 0.060469, 0.000000, 260.845062, 0.000000, .longpickup = true, .maxhitpoints = 5);
	item_SeedBag		= DefineItemType("Seeds",				"SeedBag",			2663,	2,	0.0, 0.0, 0.0,			0.205,	0.320356, 0.042146, 0.049817, 0.000000, 260.512817, 349.967254, false, 0xFFF4A460, .maxhitpoints = 2);
	item_Note			= DefineItemType("Note",				"Note",				2953,	1,	0.0, 0.0, 0.0,			0.0,	0.083999, 0.022000, -0.013000,  -82.300018, -14.900006, -83.200042, false, 0xCAFFFFFF, .maxhitpoints = 1);
	item_Tomato			= DefineItemType("Tomato",				"Tomato",			19577,	1,	170.0, 0.0, 0.0,		0.03,	0.054000, 0.055999, 0.013999, 0.000000, 0.000003, 0.000003, .maxhitpoints = 1);
// 200
	item_HeartShapedBox	= DefineItemType("Heart Shaped Box",	"HeartShapedBox",	1240,	1,	90.0, 0.0, 0.0,			-0.02,	0.171999, 0.077999, -0.016999,  0.000000, 0.000000, 10.200000, .longpickup = true, .maxhitpoints = 1);
	item_AntiSepBandage	= DefineItemType("Antiseptic Bandage",	"AntiSepBandage",	11748,	2,	0.0, 0.0, 0.0,			0.01,	0.072000, 0.041999, 0.000000,  90.299995, 1.500011, 103.599960, .maxhitpoints = 2);
	item_WoodLog		= DefineItemType("Wood Log",			"WoodLog",			19793,	1,	0.0, 0.0, 0.0,			0.000,	0.034999, 0.018998, -0.150000,  -74.199989, -110.000022, -54.900020, .maxhitpoints = 1);
	item_Sledgehammer	= DefineItemType("Sledgehammer",		"Sledgehammer",		19631,	7,	0.0, 90.0, 0.0,			0.000,	0.075000, -0.004000, 0.269000,  -84.600021, -70.899993, 0.000000, .maxhitpoints = 7);
	item_RawFish		= DefineItemType("Fish",				"RawFish",			19630,	9,	0.0, 0.0, 0.0,			0.000,	0.047000, 0.021999, 0.083000,  -84.299980, -75.299972, 103.100028, .maxhitpoints = 9);
	item_Spanner		= DefineItemType("Wrench",				"Spanner",			19627,	1,	0.0, 0.0, 0.0,			0.000,	0.073000, 0.022000, 0.035000,  -84.299980, -75.299972, 103.100028, .maxhitpoints = 1);
	item_Suitcase		= DefineItemType("Suitcase",			"Suitcase",			19624,	4,	0.0, 0.0, 0.0,			0.371,	0.086000, 0.022000, 0.022000,  -84.299980, -75.299972, 103.100028, .longpickup = true, .maxhitpoints = 4);
	item_OilCan			= DefineItemType("Oilcan",				"OilCan",			19621,	2,	0.0, 0.0, 0.0,			0.060,	0.075999, 0.022000, 0.011000,  7.800007, -11.899963, 81.800025, .maxhitpoints = 2);
	item_RadioBox		= DefineItemType("Small Amp",			"RadioBox",			19612,	8,	0.0, 0.0, 0.0,			-0.020,	-0.090000, 0.132999, -0.202000,  63.499916, 108.599983, 95.499877, .maxhitpoints = 8);
	item_BigSword		= DefineItemType("Big Ass Sword",		"BigSword",			19590,	3,	0.0, 90.0, 0.0,			-0.019,	0.069000, 0.030999, 0.012000,  53.499919, -99.100090, 146.499862, .maxhitpoints = 3);
// 210
	item_Microphone		= DefineItemType("Microphone",			"Microphone",		19610,	1,	0.0, 0.0, 0.0,			0.000,	0.078000, 0.030999, 0.012000,  53.499919, -99.100090, -46.300144, .maxhitpoints = 1);
	item_Spatula		= DefineItemType("Spatula",				"Spatula",			19586,	1,	0.0, 0.0, 0.0,			0.000,	0.078000, 0.030999, 0.012000,  53.499919, -99.100090, 150.899887, .maxhitpoints = 1);
	item_Pan			= DefineItemType("Pan",					"Pan",				19584,	2,	0.0, 0.0, 0.0,			0.100,	0.078000, 0.030999, 0.012000,  39.499954, -77.500083, 128.299819, .maxhitpoints = 2);
	item_Knife2			= DefineItemType("Kitchen Knife",		"Knife2",			19583,	1,	0.0, 0.0, 0.0,			0.000,	0.085999, 0.024999, 0.000000,  -94.000007, 179.299957, 0.599997, .maxhitpoints = 1);
	item_Meat2			= DefineItemType("Meat",				"Meat2",			19582,	1,	0.0, 0.0, 0.0,			0.000,	0.044000, 0.017999, 0.099000,  90.099960, 7.200009, 1.799715, .maxhitpoints = 1);
	item_FryingPan		= DefineItemType("Frying Pan",			"FryingPan",		19581,	2,	0.0, 0.0, 0.0,			-0.028,	0.078000, 0.017999, 0.025000,  -29.900056, -88.800018, 59.299705, .maxhitpoints = 2);
	item_PizzaOnly		= DefineItemType("Pizza",				"PizzaOnly",		19580,	3,	0.0, 0.0, 0.0,			0.000,	0.078000, 0.017999, 0.025000,  -29.900056, -88.800018, 59.299705, .maxhitpoints = 3);
	item_BreadLoaf		= DefineItemType("Loaf of Bread",		"BreadLoaf",		19579,	2,	0.0, 0.0, 0.0,			0.000,	0.232000, 0.053998, 0.047000,  83.599945, -56.300045, 100.099731, .maxhitpoints = 2);
	item_Banana			= DefineItemType("Banana",				"Banana",			19578,	1,	0.0, 0.0, 0.0,			0.000,	0.059000, 0.017998, 0.026000,  86.399932, -161.300003, 83.699714, .maxhitpoints = 1);
	item_Orange			= DefineItemType("Orange",				"Orange",			19574,	1,	0.0, 0.0, 0.0,			0.000,	0.078000, 0.040998, 0.009000,  86.399932, -161.300003, 83.699714, .maxhitpoints = 1);
// 220
	item_WheelLock		= DefineItemType("Lock and Chain",		"WheelLock",		2680,	1,	0.0, 0.0, 0.0,			0.000,	0.215000, -0.037999, 0.059000,  -48.999996, -110.599960, -54.000000, .maxhitpoints = 1);
	item_RedApple		= DefineItemType("Red Apple",			"RedApple",			19575,	1,	170.0, 0.0, 0.0,		0.03,	0.100000, 0.039000, 0.018000,  4.400032, -2.300116, 138.699905, .maxhitpoints = 1);
	item_Lemon			= DefineItemType("Lemon",				"Lemon",			19574,	1,	170.0, 0.0, 0.0,		0.03,	0.000003, 0.000003, 0.000003, 0.000000, 0.000003, 0.000003, .maxhitpoints = 1);
	item_PisschBox		= DefineItemType("Pissh Box",			"PisschBox",		19572,	2,	0.0, 0.0, 0.0,			0.0363,	-0.001000, -0.043999, -0.167999,  -110.499992, -12.499979, 83.099990, .maxhitpoints = 2);
	item_PizzaBox		= DefineItemType("Pizza Box",			"PizzaBox",			19571,	3,	90.0, 0.0, 0.0,			0.0,	0.263000, 0.057999, -0.184000,  0.000000, 0.000000, 0.000000, .maxhitpoints = 3);
	item_MilkBottle		= DefineItemType("Milk Bottle",			"MilkBottle",		19570,	1,	0.0, 0.0, 0.0,			0.0199,	0.069000, 0.043999, -0.276000,  0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_MilkCarton		= DefineItemType("Milk Carton",			"MilkCarton",		19569,	1,	0.0, 0.0, 0.0,			0.0298,	0.128000, 0.083999, -0.129000,  0.000000, 0.000000, 0.000000, .maxhitpoints = 1);
	item_IceCream		= DefineItemType("Ice Cream",			"IceCream",			19568,	1,	0.0, 0.0, 0.0,			0.0308,	0.233000, 0.152999, 0.056999,  95.200012, -3.199998, 11.200000, .maxhitpoints = 1);
	item_FishyFingers	= DefineItemType("Fishy Fingers",		"FishyFingers",		19566,	1,	-91.0, 0.0, 0.0,		-0.009,	0.272000, 0.000999, 0.164999,  -161.999969, 8.400005, -1.699998, .maxhitpoints = 1);
	item_IceCreamBars	= DefineItemType("Ice Cream Bars",		"IceCreamBars",		19565,	1,	-90.0, 0.0, 0.0,		-0.01,	0.272000, 0.000999, 0.180999,  -161.999969, 8.400005, -1.699998, .maxhitpoints = 1);
// 230
	item_AppleJuice		= DefineItemType("Apple Juice",			"AppleJuice",		19564,	1,	0.0, 0.0, 0.0,			0.039,	0.099000, 0.009999, 0.145999,  -161.999969, 8.400005, -1.699998, .maxhitpoints = 1);
	item_OrangeJuice	= DefineItemType("Orange Juice",		"OrangeJuice",		19563,	1,	0.0, 0.0, 0.0,			0.026,	0.177000, 0.088999, -0.118000,  -161.999969, -165.499984, -1.699998, .maxhitpoints = 1);
	item_Cereal1		= DefineItemType("Cereal",				"Cereal1",			19562,	1,	0.0, 0.0, 0.0,			0.022,	0.245000, 0.123999, -0.175000,  -161.999969, -165.499984, -1.699998, .maxhitpoints = 1);
	item_Cereal2		= DefineItemType("Cereal",				"Cereal2",			19561,	1,	0.0, 0.0, 0.0,			0.022,	0.245000, 0.123999, -0.175000,  -161.999969, -165.499984, -1.699998, .maxhitpoints = 1);
	item_WrappedMeat	= DefineItemType("Wrapped Meat",		"WrappedMeat",		19560,	1,	0.0, 0.0, 0.0,			0.0,	0.223000, 0.052999, 0.064999,  -70.300064, 165.600082, 10.500000, .maxhitpoints = 1);
	item_Beanie			= DefineItemType("Beanie",				"Beanie",			19554,	1,	-25.0, -91.0, -91.0,	0.0,	0.138000, 0.046000, 0.000000,  -107.600021, 174.399978, 0.000000, .maxhitpoints = 1);
	item_StrawHat		= DefineItemType("Straw Hat",			"StrawHat",			19553,	1,	0.0, -105.0, 0.0,		-0.039,	0.210999, 0.018000, 0.053999,  -107.600021, 81.099998, 0.000000, .maxhitpoints = 1);
	item_WitchesHat		= DefineItemType("Witches Hat",			"WitchesHat",		19528,	1,	0.0, -84.0, 0.0,		0.0,	0.290000, 0.018000, 0.053999,  -107.600021, 102.500000, 0.000000, .maxhitpoints = 1);
	item_WeddingCake	= DefineItemType("Wedding Cake",		"WeddingCake",		19525,	1,	0.0, 0.0, 0.0,			0.036,	0.076999, 0.032000, -0.126000,  -179.400054, -175.200042, -2.499999, .maxhitpoints = 1);
	item_CaptainsCap	= DefineItemType("Captain's Cap",		"CaptainsCap",		19520,	1,	0.0, -91.0, 11.0,		0.0,	0.157999, 0.043000, 0.020999,  76.099891, -100.200050, -2.499999, .maxhitpoints = 1);
// 240
	item_SwatHelmet		= DefineItemType("Swat Helmet",			"SwatHelmet",		19514,	1,	-22.0, -98.0, 2.0,		0.0,	0.186999, 0.043000, 0.029999,  76.099891, -68.100074, -2.499999, .maxhitpoints = 1);
	item_PizzaHat		= DefineItemType("Pizza Hat",			"PizzaHat",			19558,	1,	2.0, -93.0, 0.0,		0.0,	0.186999, 0.043000, 0.012999,  9.900009, -175.300125, -94.199996, .maxhitpoints = 1);
	item_PussyMask		= DefineItemType("Pussy Mask",			"PussyMask",		19557,	1,	0.0, 265.0, 0.0,		-0.059,	0.146999, -0.009999, 0.012999,  5.600010, -84.900131, -109.300079, .maxhitpoints = 1);
	item_BoxingGloves	= DefineItemType("Boxing Gloves",		"BoxingGloves",		19556,	1,	-91.0, 0.0, 0.0,		0.0,	0.146999, 0.011000, 0.028000,  8.100008, -100.500106, -17.300100, .maxhitpoints = 1);
	item_Briquettes		= DefineItemType("Briquettes",			"Briquettes",		19573,	1,	0.0, 0.0, 0.0,			0.036,	0.616000, -0.044999, 0.120000,  8.100008, -100.500106, 6.299896, .maxhitpoints = 1);
	item_DevilMask		= DefineItemType("Devil Mask",			"DevilMask",		11704,	1,	-76.0, 0.0, 0.0,		0.0,	0.371000, -0.044999, 0.040000,  8.100008, -100.500106, 6.299896, .maxhitpoints = 1);
	item_Cross			= DefineItemType("Cross",				"Cross",			11712,	1,	0.0, 90.0, 90.0,		0.0,	0.087000, 0.037000, 0.061000,  8.100008, -1.800116, 6.299896, .maxhitpoints = 1);
	item_RedPanel		= DefineItemType("Red Panel",			"RedPanel",			11713,	5,	0.0, -90.0, 90.0,		0.0,	0.001000, 0.268000, -0.258999,  -20.299985, -2.300116, 17.399898, true, .maxhitpoints = 5);
	item_Fork			= DefineItemType("Fork",				"Fork",				11715,	1,	0.0, 0.0, 0.0,			0.0,	0.086000, 0.039000, 0.068000,  88.800025, -2.300116, 1.699898, .maxhitpoints = 1);
	item_Knife3			= DefineItemType("Knife",				"Knife3",			11716,	1,	0.0, 0.0, 0.0,			0.0,	0.067000, 0.006999, 0.064999,  -74.700141, 164.000076, -165.100036, .maxhitpoints = 1);
// 250
	item_Ketchup		= DefineItemType("Ketchup",				"Ketchup",			11722,	1,	0.0, 0.0, 0.0,			-0.1,	0.100000, 0.077000, 0.041000,  4.400032, -2.300116, 138.699905, .maxhitpoints = 1);
	item_Mustard		= DefineItemType("Mustard",				"Mustard",			11723,	1,	0.0, 0.0, 0.0,			-0.1,	0.100000, 0.077000, 0.041000,  4.400032, -2.300116, 138.699905, .maxhitpoints = 1);
	item_Boot			= DefineItemType("Boot",				"Boot",				11735,	2,	0.0, 0.0, 0.0,			0.02,	0.193000, 0.030000, -0.266999,  -4.899966, -6.200114, 84.699867, .maxhitpoints = 2);
	item_Doormat		= DefineItemType("Doormat",				"Doormat",			11737,	3,	0.0, 0.0, 0.0,			0.02,	0.441000, 0.027000, 0.017999,  96.300025, -2.500113, 97.699829, .maxhitpoints = 3);
	item_CakeSlice		= DefineItemType("Cake Slice",			"CakeSlice",		11742,	1,	0.0, 0.0, 0.0,			0.026,	0.107000, 0.052000, 0.017999,  96.300025, -87.400100, 7.399830, .maxhitpoints = 1);
	item_Holdall		= DefineItemType("Holdall",				"Holdall",			11745,	4,	0.0, 0.0, 0.0,			0.113,	-0.015999, 0.150000, -0.187000,  74.200035, -161.400177, -6.000168, true, .longpickup = true, .maxhitpoints = 4);
	item_GrnApple		= DefineItemType("Green Apple",			"GrnApple",			19576,	1,	0.0, 0.0, 0.0,			0.03,	0.107000, 0.039000, 0.014999,  -168.799911, -161.400177, -0.400169, .maxhitpoints = 1);
	item_Wine1			= DefineItemType("Wine",				"Wine1",			19820,	1,	0.0, 0.0, 0.0,			0.0,	0.169000, 0.053000, -0.506999,  -178.499954, -170.700210, -10.200168, .maxhitpoints = 1);
	item_Wine2			= DefineItemType("Wine",				"Wine2",			19821,	1,	0.0, 0.0, 0.0,			0.0,	0.169000, 0.053000, -0.506999,  -178.499954, -170.700210, -10.200168, .maxhitpoints = 1);
	item_Wine3			= DefineItemType("Wine",				"Wine3",			19822,	1,	0.0, 0.0, 0.0,			0.0,	0.169000, 0.053000, -0.423999,  -178.499954, -170.700210, -10.200168, .maxhitpoints = 1);
// 260
	item_Whisky			= DefineItemType("Whisky",				"Whisky",			19823,	1,	0.0, 0.0, 0.0,			0.0,	0.132000, 0.041000, -0.286999,  -178.499954, -170.700210, -10.200168, .maxhitpoints = 1);
	item_Champagne		= DefineItemType("Champagne",			"Champagne",		19824,	1,	0.0, 0.0, 0.0,			0.0,	0.132000, 0.041000, -0.346999,  -178.499954, -170.700210, -10.200168, .maxhitpoints = 1);
	item_Ham			= DefineItemType("Ham",					"Ham",				19847,	1,	0.0, 0.0, 0.0,			0.0,	0.085000, 0.024000, 0.044000,  -77.199935, -167.100173, 15.799836, .maxhitpoints = 1);
	item_Steak			= DefineItemType("Steak",				"Steak",			19882,	1,	0.0, 0.0, 0.0,			-0.02,	0.148000, 0.024000, 0.044000,  -77.199935, -167.100173, 15.799836, .maxhitpoints = 1);
	item_Bread			= DefineItemType("Bread",				"Bread",			19883,	1,	0.0, 0.0, 0.0,			-0.02,	0.148000, 0.024000, 0.026000,  -77.199935, 174.499786, 15.799836, .maxhitpoints = 1);
	item_Broom			= DefineItemType("Broom",				"Broom",			19622,	4,	91.5, 0.0, 0.0,			0.0,	0.051000, -0.024999, 0.358000,  11.400080, 174.499786, 18.599828, .maxhitpoints = 4);
	item_Keycard		= DefineItemType("Keycard",				"Keycard",			19792,	1,	0.0, 0.0, 0.0,			0.0,	0.081000, 0.039000, 0.014000,  95.100082, 174.499786, 83.799827, .maxhitpoints = 1);
	item_BurntLog		= DefineItemType("Burnt Log",			"BurntLog",			19793,	3,	0.0, 0.0, 0.0,			0.046,	0.079000, 0.039000, -0.194999,  73.600059, -175.100250, 83.199836, true, 0xFF000000, .maxhitpoints = 3);
	item_Padlock		= DefineItemType("Padlock",				"Padlock",			19804,	1,	90.0, 0.0, 0.0,			-0.016,	0.160000, 0.035000, 0.019000,  75.900054, -91.200210, 85.499847, .maxhitpoints = 1);
	item_OilDrum		= DefineItemType("Oil Drum",	 		"OilDrum",			19812,	5,	0.0, 0.0, 0.0,			0.468,	0.053000, 0.480999, -0.340999,  -109.899971, -10.700182, 98.799865, true, .maxhitpoints = 5);
// 270
	item_Canister		= DefineItemType("Canister",			"Canister",			19816,	5,	0.0, 0.0, 0.0,			0.218,	0.081000, 0.032999, -0.195999,  164.900070, 8.099815, 96.199882, true, .maxhitpoints = 5);
	item_ScrapMetal		= DefineItemType("Scrap Metal",			"ScrapMetal",		19941,	1,	0.0, 0.0, 0.0,			0.218,	0.110999, 0.031000, 0.031999,  -101.400001, 3.700001, -97.499969, false, 0xFF4D2525, .maxhitpoints = 1);
	item_RefinedMetal	= DefineItemType("Refined Metal",		"RefinedMetal",		19941,	1,	0.0, 0.0, 0.0,			0.218,	0.110999, 0.031000, 0.031999,  -101.400001, 3.700001, -97.499969, false, 0xFFE35454, .maxhitpoints = 1);
	item_Locator		= DefineItemType("Locator",				"Locator",			2967,	1,	0.0, 0.0, 0.0,			0.0,	0.095999, 0.064999, 0.000000, -1.300025, -67.899948, -92.999908, .maxhitpoints = 1);
	item_PlotPole		= DefineItemType("Plot Pole",			"PlotPole",			3221,	3,	0.0, 0.0, 0.0,			0.0,	0.081356, 0.034642, -0.167247, 0.000000, 0.000000, 240.265777, .maxhitpoints = 3);
	item_ScrapMachine	= DefineItemType("Scrap Machine",		"ScrapMachine",		920,	12,	0.0, 0.0, 0.0,			0.4344,	.maxhitpoints = 12);
	item_RefineMachine	= DefineItemType("Refining Machine",	"RefineMachine",	943,	12,	0.0, 0.0, 0.0,			0.7208,	.maxhitpoints = 12);
	item_WaterMachine	= DefineItemType("Water Purifier",		"WaterMachine",		958,	12,	0.0, 0.0, 0.0,			0.8195,	.maxhitpoints = 12);
	item_Workbench		= DefineItemType("Workbench",			"Workbench",		936,	12,	0.0, 0.0, 0.0,			0.4434,	.longpickup = true, .maxhitpoints = 12);
	item_Radio			= DefineItemType("Radio",				"Radio",			2966,	1,	0.0, 0.0, 0.0,			0.0,	0.073999, 0.066999, -0.057000,  101.699996, -151.699951, 0.000000, .maxhitpoints = 1);
// 280
	item_Locker			= DefineItemType("Locker",				"Locker",			11729,	12,	0.0, 0.0, 0.0,			0.0,	.longpickup = true,	.maxhitpoints = 10);
	item_GearBox		= DefineItemType("Gear Box",			"GearBox",			19918,	5,	0.0, 0.0, 0.0,			-0.0361,0.073999, -0.039000, -0.169000,  73.400024, -173.499984, 80.899993, .longpickup = true, .maxhitpoints = 4);
	item_ToolBox		= DefineItemType("Tool Box",			"ToolBox",			19921,	7,	0.0, 0.0, 0.0,			0.0541,	-0.209000, 0.052999, -0.231000,  73.400024, -173.499984, 80.899993, true, .longpickup = true, .maxhitpoints = 8);
	item_MetalFrame		= DefineItemType("Metal Panel",			"MetalFrame",		19843,	10,	0.0, 0.0, 0.0,			0.0,	-0.093000, 0.414000, -0.347999,  77.500022, 105.500022, 80.100013, true, .maxhitpoints = 16);
	item_LockBreaker	= DefineItemType("Electronic Lockpick",	"LockBreaker",		1952,	2,	0.0, 0.0, 0.0,			0.001,	0.098000, 0.039999, 0.085000,  -94.900032, -177.600021, 18.499980, .maxhitpoints = 2);
	item_PoliceHelm		= DefineItemType("Police Helmet",		"PoliceHelm",		19200,	1,	0.0, 0.0, 0.0,			0.05,	0.173000, -0.010000, -0.020000,  -90.299995, 0.000000, 0.000000, .maxhitpoints = 1);
	item_ControlBox		= DefineItemType("Control Box",			"ControlBox",		1958,	2,	0.0, 0.0, 0.0,			0.0211);
	item_Computer		= DefineItemType("Computer",			"Computer",			1719,	2,	0.0, 0.0, 0.0,			0.0251);
	item_TallFrame		= DefineItemType("Metal Frame",			"TallFrame",		3025,	14,	0.0, 180.0, 0.0,			0.0);
	item_RemoteControl	= DefineItemType("IR Controller",		"RemoteControl",	19920,	1,	4.0, 0.0, 0.0,			-0.0200);
// 290
	item_Desk			= DefineItemType("Desk",				"Desk",				2180,	14,	0.0, 0.0, 0.0,			-0.0320, .maxhitpoints = 14, .longpickup = true);
	item_Table			= DefineItemType("Table",				"Table",			2115,	14,	0.0, 0.0, 0.0,			-0.0280, .maxhitpoints = 14, .longpickup = true);
	item_GunCase		= DefineItemType("Gun Case",			"GunCase",			2046,	12,	0.0, 0.0, 0.0,			0.5, .maxhitpoints = 12, .longpickup = true);
	item_Cupboard		= DefineItemType("Cupboard",			"Cupboard",			19932,	12,	0.0, 0.0, 90.0,			0.0, .maxhitpoints = 12, .longpickup = true);
	item_Barstool		= DefineItemType("Barstool",			"Barstool",			1805,	8,	0.0, 0.0, 0.0,			0.22, .maxhitpoints = 8, .longpickup = true);
	item_SmallTable		= DefineItemType("Small Table",			"SmallTable",		2346,	10,	0.0, 0.0, 0.0,			-0.03, .maxhitpoints = 10, .longpickup = true);
	item_BandanaBlue	= DefineItemType("Bandana",				"BandanaBl",		18917,	1,	0.0, 0.0, 0.0,			0.0,	0.095999, 0.064999, 0.000000, -1.300025, -67.899948, -92.999908);
	item_BandanaGrey	= DefineItemType("Bandana",				"BandanaGr",		18918,	1,	0.0, 0.0, 0.0,			0.0,	0.095999, 0.064999, 0.000000, -1.300025, -67.899948, -92.999908);
	item_BandanaWhite	= DefineItemType("Bandana",				"BandanaWh",		18919,	1,	0.0, 0.0, 0.0,			0.0,	0.095999, 0.064999, 0.000000, -1.300025, -67.899948, -92.999908);
	item_BandanaPattern	= DefineItemType("Bandana",				"BandanaPat",		18920,	1,	0.0, 0.0, 0.0,			0.0,	0.095999, 0.064999, 0.000000, -1.300025, -67.899948, -92.999908);
}
