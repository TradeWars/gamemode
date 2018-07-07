Load_BC()
{
	CreateFuelOutlet(603.48438, 1707.23438, 6.17969, 2.0, 130.0, frandom(40));
	CreateFuelOutlet(606.89844, 1702.21875, 6.17969, 2.0, 130.0, frandom(40));
	CreateFuelOutlet(610.25000, 1697.26563, 6.17969, 2.0, 130.0, frandom(40));
	CreateFuelOutlet(613.71875, 1692.26563, 6.17969, 2.0, 130.0, frandom(40));
	CreateFuelOutlet(617.12500, 1687.45313, 6.17969, 2.0, 130.0, frandom(40));
	CreateFuelOutlet(620.53125, 1682.46094, 6.17969, 2.0, 130.0, frandom(40));
	CreateFuelOutlet(624.04688, 1677.60156, 6.17969, 2.0, 130.0, frandom(40));
/*
	new
		buttonid[2];

	buttonid[0]=CreateButton(-101.579933, 1374.613769, 10.4698, "Press F to enter", 0, 0, .label = 1);
	buttonid[1]=CreateButton(-217.913787, 1402.804199, 27.7734, "Press F to exit", 0, 18, .label = 1);
	LinkTP(buttonid[0], buttonid[1]);

	buttonid[0]=CreateButton(-89.3299, 1378.2357, 10.4698, "Press F to enter", 0, 0, .label = 1);
	buttonid[1]=CreateButton(-229.2949, 1401.2293, 27.7656, "Press F to exit", 0, 18, .label = 1);
	LinkTP(buttonid[0], buttonid[1]);
*/

//	CreateTurret(287.0, 2047.0, 17.5, 270.0, .type = 1);
//	CreateTurret(335.0, 1843.0, 17.5, 270.0, .type = 1);
//	CreateTurret(10.0, 1805.0, 17.40, 180.0, .type = 1);

	BC_District_Payasdas();
	BC_District_Verdant();
	BC_District_Area69();
	BC_District_BoneEast();
	BC_District_BigEar();
	BC_District_Probe();
	BC_District_Octane();
	BC_District_Carson();
	BC_District_Hunter();
	BC_District_BoneGen();

	DefineSupplyDropPos("Fort Carson", 7.24142, 959.94550, 18.55249);
	DefineSupplyDropPos("Bone County East", 631.26288, 1587.61060, 6.64180);
	DefineSupplyDropPos("Bone County Canyons", -301.43231, 1877.09180, 41.23884);
	DefineSupplyDropPos("Verdant Meadows", 373.16586, 2511.17383, 15.47215);
}


BC_District_Payasdas()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Payasdas' please wait...");
}

BC_District_Verdant()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Verdant' please wait...");

	CreateHackerTrap(7412.60131, 2543.074218, 25.582199,			GetLootIndexFromName("world_military"));
}

BC_District_Area69()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Area69' please wait...");

	CreateHackerTrap(250.966644, 1777.734375, 4.161170,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(252.487274, 1785.738159, 4.164050,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(251.883483, 1783.548706, 4.163259,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(252.522598, 1785.029907, 4.163790,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(253.905334, 1785.449951, 4.163949,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(253.226806, 1783.215087, 4.163139,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(251.440322, 1785.401123, 4.163919,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(246.760894, 1787.169311, 4.164539,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(248.001358, 1787.676757, 4.164720,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(247.618255, 1785.863647, 4.164070,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(249.861343, 1785.931396, 4.164100,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(248.888107, 1785.989746, 4.164120,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(254.268676, 1784.390625, 4.163579,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(247.033706, 1784.185424, 4.163459,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(248.984436, 1784.533447, 4.163599,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(246.312789, 1780.512939, 4.162129,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(249.651947, 1777.317626, 4.161009,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(246.838943, 1777.742797, 4.161149,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(251.380920, 1781.127563, 4.162370,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(252.917343, 1781.226562, 4.162409,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(254.308044, 1781.366699, 4.162489,				GetLootIndexFromName("world_military"));
	CreateHackerTrap(249.463699, 1782.034301, 4.162690,				GetLootIndexFromName("world_military"));
}

BC_District_BoneEast()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_BoneEast' please wait...");
}

BC_District_BigEar()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_BigEar' please wait...");
}

BC_District_Probe()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Probe' please wait...");
}

BC_District_Octane()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Octane' please wait...");
}

BC_District_Carson()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Carson' please wait...");

	CreateItem(item_Workbench, 318.60028, 1145.81543, 7.54844, 0.0, 0.0, -181.56007);
}

BC_District_Hunter()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_Hunter' please wait...");

	CreateItem(item_Workbench, 585.17377, 873.72583, -43.51944, 0.0, 0.0, 94.26003);
}

BC_District_BoneGen()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'BC_District_BoneGen' please wait...");

	CreateItem(item_Workbench, -371.56595, 2235.98975, 41.43906, 0.0, 0.0, 12.84000);
}
