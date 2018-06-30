Load_LV()
{
	CreateFuelOutlet(2120.82031, 914.718750, 11.25781, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2114.90625, 914.718750, 11.25781, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2109.04688, 914.718750, 11.25781, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2120.82031, 925.507810, 11.25781, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2114.90625, 925.507810, 11.25781, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2109.04688, 925.507810, 11.25781, 2.0, 100.0, frandom(25.0));

	CreateFuelOutlet(2207.69531, 2480.32813, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2207.69531, 2474.68750, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2207.69531, 2470.25000, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2196.89844, 2480.32813, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2196.89844, 2474.68750, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2196.89844, 2470.25000, 11.31250, 2.0, 100.0, frandom(25.0));

	CreateFuelOutlet(2153.31250, 2742.52344, 11.27344, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2147.53125, 2742.52344, 11.27344, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2141.67188, 2742.52344, 11.27344, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2153.31250, 2753.32031, 11.27344, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2147.53125, 2753.32031, 11.27344, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(2141.67188, 2753.32031, 11.27344, 2.0, 100.0, frandom(25.0));

	CreateFuelOutlet(1590.35156, 2204.50000, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(1596.13281, 2204.50000, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(1602.00000, 2204.50000, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(1590.35156, 2193.71094, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(1596.13281, 2193.71094, 11.31250, 2.0, 100.0, frandom(25.0));
	CreateFuelOutlet(1602.00000, 2193.71094, 11.31250, 2.0, 100.0, frandom(25.0));

	CreateFuelOutlet(2634.64063, 1100.94531, 11.25000, 2.0, 100.0, frandom(20.0));
	CreateFuelOutlet(2639.87500, 1100.96094, 11.25000, 2.0, 100.0, frandom(20.0));
	CreateFuelOutlet(2645.25000, 1100.96094, 11.25000, 2.0, 100.0, frandom(20.0));
	CreateFuelOutlet(2634.64063, 1111.75000, 11.25000, 2.0, 100.0, frandom(20.0));
	CreateFuelOutlet(2639.87500, 1111.75000, 11.25000, 2.0, 100.0, frandom(20.0));
	CreateFuelOutlet(2645.25000, 1111.75000, 11.25000, 2.0, 100.0, frandom(20.0));

	CreateLadder(1177.6424, -1305.6337, 13.9241, 29.0859, 0.0);

	LV_District_Housing1();
	LV_District_Housing2();
	LV_District_Housing3();
	LV_District_KACC();
	LV_District_City1();
	LV_District_City2();
	LV_District_Strip();
	LV_District_Airport();
	LV_District_Industrial1();
	LV_District_Industrial2();

	DefineSupplyDropPos("Las Venturas Stadium", 1344.11108, 2149.04517, 9.93602);
	DefineSupplyDropPos("Las Venturas North Strip Motel", 2080.01758, 2172.97900, 9.76857);
	DefineSupplyDropPos("Las Venturas East Shopping Mall", 2614.95264, 1766.20935, 9.74024);
	DefineSupplyDropPos("Las Venturas East Building Roof", 2644.05469, 1211.56506, 25.86082);
	DefineSupplyDropPos("Las Venturas South Industrial", 1692.09644, 956.23187, 9.69593);
	DefineSupplyDropPos("Las Venturas Airport", 1346.64453, 1591.55396, 9.70243);
}


LV_District_Housing1()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Housing1' please wait...");
}

LV_District_Housing2()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Housing2' please wait...");
}

LV_District_Housing3()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Housing3' please wait...");
}

LV_District_KACC()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_KACC' please wait...");

	new buttonid[1];

	// Requires "./scriptfiles/Maps/LV/KACC.map" to remove:
	// RemoveBuildingForPlayer(playerid, 985, 2497.36523438, 2777.06933594, 11.55891800, 40.0);
	// RemoveBuildingForPlayer(playerid, 986, 2497.35888672, 2769.11181641, 11.55891800, 40.0);

	CreateObject(19273, 2503.98120, 2780.09302, 11.36690, 0.00000, 0.00000, 90.00000);

	buttonid[0] = CreateButton(2503.98120, 2780.09302, 11.36690, "Press "KEYTEXT_INTERACT" to activate");

	CreateDoor(985, buttonid,
		2497.36523438, 2777.06933594, 11.55891800, 0.00000000, 0.00000000, 90.00000000,
		2497.36523438, 2785.06933594, 11.55891800, 0.00000000, 0.00000000, 90.00000000,
		.movesound = 6000, .stopsound = 6002);

	CreateDoor(986, buttonid,
		2497.35888672, 2769.11181641, 11.55891800, 0.00000000, 0.00000000, 90.00000000,
		2497.36523438, 2761.11181641, 11.55891800, 0.00000000, 0.00000000, 90.00000000,
		.movesound = 6000, .stopsound = 6002);
}

LV_District_City1()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_City1' please wait...");

	CreateItem(ItemType:11, 2543.21313, 1025.56433, 11.10866, 66.0000, 4.0, 0.0);
}

LV_District_City2()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_City2' please wait...");
}

LV_District_Strip()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Strip' please wait...");
}

LV_District_Airport()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Airport' please wait...");
}

LV_District_Industrial1()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Industrial1' please wait...");
}

LV_District_Industrial2()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'LV_District_Industrial2' please wait...");
}
