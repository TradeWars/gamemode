Load_SF()
{
	// CreateLadder(-1164.6187, 370.0174, 1.9609, 14.1484, 221.1218);
	// CreateLadder(-1182.6258, 60.4429, 1.9609, 14.1484, 134.2914);
	// CreateLadder(-1736.4494, -445.9549, 1.9609, 14.1484, 270.7138);

	SF_District_Housing1();
	SF_District_Housing2();
	SF_District_Bayfront();
	SF_District_City1();
	SF_District_City2();
	SF_District_Naval();
	SF_District_Police();
	SF_District_Industrial();
	SF_District_SfAirport();
	SF_District_MontFoster();
	SF_District_Ship1();
	SF_District_Ship2();

/*
	// SF Factory
	LinkTP(
		CreateButton(-904.7388, 335.7443, 1014.1530, "Press F to open", 0),
		CreateButton(-1857.1831, -169.5322, 9.1358, "Press F to open", 0));

	// SF utility room
	LinkTP(
		CreateButton(-2578.1204, 1144.8810, 40.3989, "Press F to enter"),
		CreateButton(-2587.5229, 1162.4547, 55.5876, "Press F to enter"));
*/

	// DefineSupplyDropPos("San Fierro Airport", -1312.81885, -16.52664, 13.08027);
	// DefineSupplyDropPos("San Fierro Driving School", -2055.64697, -200.37950, 34.24461);
	// DefineSupplyDropPos("San Fierro Country Club", -2767.39209, -287.28488, 5.98262);
	// DefineSupplyDropPos("San Fierro Hospital", -2569.96948, 653.26270, 26.74425);
	// DefineSupplyDropPos("San Fierro Square", -1980.58887, 884.61041, 44.17714);
	// DefineSupplyDropPos("San Fierro Promenade", -1587.81201, 1180.50891, 5.97472);
}


SF_District_Housing1()
{
	// // ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Housing1' please wait...");

	// CreateSaveBlockArea(CreateDynamicCube(-2521.3608, 286.6024, 1035.3081, -2478.7195, 328.1099, 1039.7107), -2499.1262, 315.1892, 29.4147);

	// DefineWeaponsCachePos(-2716.43823, 382.60507, 3.34639);
	// DefineWeaponsCachePos(-2521.67456, 318.69183, 34.09675);
	// DefineWeaponsCachePos(-2473.95605, 401.25406, 26.73841);
	// DefineWeaponsCachePos(-2587.40479, 332.89505, 3.84088);
	// DefineWeaponsCachePos(-2684.57642, 268.28076, 3.31175);
	// DefineWeaponsCachePos(-2641.14673, 190.63800, 3.30231);
	// DefineWeaponsCachePos(-2752.70020, 206.10161, 5.93917);
	// DefineWeaponsCachePos(-2980.13965, 468.74667, 3.87113);
	// DefineWeaponsCachePos(-2755.74316, 96.59800, 6.01551);
	// DefineWeaponsCachePos(-2679.01245, -22.84922, 3.30198);
	// DefineWeaponsCachePos(-2655.62231, 88.49954, 3.07376);
	// DefineWeaponsCachePos(-2524.37085, -7.58145, 24.60770);
	// DefineWeaponsCachePos(-2456.55249, -22.27232, 31.77888);
	// DefineWeaponsCachePos(-2496.17969, 96.59895, 34.15479);
	// DefineWeaponsCachePos(-2311.83350, 196.26547, 34.27616);
	// DefineWeaponsCachePos(-2318.07178, 102.51508, 34.30185);
	// DefineWeaponsCachePos(-2318.58887, -3.95909, 34.31125);
	// DefineWeaponsCachePos(-2351.37231, -146.02968, 34.30040);
	// DefineWeaponsCachePos(-2487.73804, -128.85942, 24.59999);
	// DefineWeaponsCachePos(-2752.04517, -246.72028, 6.17439);
	// DefineWeaponsCachePos(-2898.28613, -35.74038, 3.17566);
	// DefineWeaponsCachePos(-2897.09619, 223.05794, 2.77412);

}
SF_District_Housing2()
{
	// // ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Housing2' please wait...");

	CreateItem(item_Barbecue, -2701.1328, 845.7422, 70.3828, 171.0);

	// CreateZipline(
	// 	-2628.34, 778.85, 54.44,
	// 	-2671.98, 726.87, 38.19);
	// CreateZipline(
	// 	-2674.76, 867.24, 82.52,
	// 	-2674.28, 820.22, 73.14);

	// CreateFuelOutlet(-2410.80, 970.85, 44.48, 2.0, 100.0, frandom(40.0));
	// CreateFuelOutlet(-2410.80, 976.19, 44.48, 2.0, 100.0, frandom(40.0));
	// CreateFuelOutlet(-2410.80, 981.52, 44.48, 2.0, 100.0, frandom(40.0));

	// DefineWeaponsCachePos(-1838.79651, 1543.79602, 6.11533);
	// DefineWeaponsCachePos(-1791.30994, 1543.37488, 6.12531);
	// DefineWeaponsCachePos(-1740.91626, 1543.25623, 6.14425);
	// DefineWeaponsCachePos(-1635.86804, 1395.58569, 6.10300);
	// DefineWeaponsCachePos(-1687.91589, 1333.41431, 16.21160);
	// DefineWeaponsCachePos(-1507.31702, 1376.17590, 2.70524);
	// DefineWeaponsCachePos(-1470.77661, 1490.27856, 7.22244);
	// DefineWeaponsCachePos(-1367.22815, 1488.73926, 10.00001);
	// DefineWeaponsCachePos(-2312.12354, 1543.81042, 17.66385);
	// DefineWeaponsCachePos(-2511.63599, 1546.00610, 16.22589);
	// DefineWeaponsCachePos(-2482.55811, 1545.02832, 31.02781);
	// DefineWeaponsCachePos(-2666.99951, 1595.01184, 216.26262);
	// DefineWeaponsCachePos(-2677.81641, 1421.06689, 22.88134);
	// DefineWeaponsCachePos(-2694.79102, 1450.10278, 6.08558);
	// DefineWeaponsCachePos(-2650.59155, 1173.00110, 34.16104);
	// DefineWeaponsCachePos(-2813.31299, 1144.59729, 19.29218);
	// DefineWeaponsCachePos(-2448.96436, 986.39960, 44.28560);
	// DefineWeaponsCachePos(-2326.22144, 1024.58105, 49.66642);
	// DefineWeaponsCachePos(-2444.17920, 749.96143, 34.14997);
	// DefineWeaponsCachePos(-2764.66406, 786.03918, 51.77070);
	// DefineWeaponsCachePos(-2568.56030, 835.23065, 49.40046);
	// DefineWeaponsCachePos(-2647.30957, 850.75775, 63.00303);
	// DefineWeaponsCachePos(-2721.87305, 976.66754, 53.45127);
	// DefineWeaponsCachePos(-2569.40210, 982.52228, 77.25880);
}
SF_District_Bayfront()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Bayfront' please wait...");

	// DefineWeaponsCachePos(-1838.79651, 1543.79602, 6.11533);
	// DefineWeaponsCachePos(-1791.30994, 1543.37488, 6.12531);
	// DefineWeaponsCachePos(-1740.91626, 1543.25623, 6.14425);
	// DefineWeaponsCachePos(-1635.86804, 1395.58569, 6.10300);
	// DefineWeaponsCachePos(-1687.91589, 1333.41431, 16.21160);
	// DefineWeaponsCachePos(-1507.31702, 1376.17590, 2.70524);
	// DefineWeaponsCachePos(-1470.77661, 1490.27856, 7.22244);
	// DefineWeaponsCachePos(-1367.22815, 1488.73926, 10.00001);
	// DefineWeaponsCachePos(-2312.12354, 1543.81042, 17.66385);
	// DefineWeaponsCachePos(-2511.63599, 1546.00610, 16.22589);
	// DefineWeaponsCachePos(-2482.55811, 1545.02832, 31.02781);
	// DefineWeaponsCachePos(-2666.99951, 1595.01184, 216.26262);
	// DefineWeaponsCachePos(-2677.81641, 1421.06689, 22.88134);
	// DefineWeaponsCachePos(-2694.79102, 1450.10278, 6.08558);
}
SF_District_City1()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_City1' please wait...");

	// new
	// 	buttonid[2];

	// buttonid[0] = CreateButton(-2208.2568, 579.8558, 35.7653, "Press F to activate", 0);
	// buttonid[1] = CreateButton(-2208.2561, 584.4679, 35.7653, "Press F to activate", 0);
	// CreateDoor(16501, buttonid,
	// 	-2211.40, 581.99, 36.37,   0.00, 0.00, 90.00,
	// 	-2211.40, 581.99, 39.61,   0.00, 0.00, 90.00, .movesound = 6000, .stopsound = 6002);

	// buttonid[0] = CreateButton(-2243.0400, 640.7287, 49.9911, "Press F to activate", 0);
	// buttonid[1] = CreateButton(-2238.6035, 641.0287, 49.9911, "Press F to activate", 0);
	// CreateDoor(16501, buttonid,
	// 	-2241.90, 643.55, 50.69,   0.00, 0.00, 0.00,
	// 	-2241.90, 643.55, 53.96,   0.00, 0.00, 0.00, .movesound = 6000, .stopsound = 6002);


	// CreateZipline(
	// 	-2176.1233, 624.6251, 64.5186,
	// 	-2199.2416, 599.1184, 58.2986);

	// CreateZipline(
	// 	-2172.7917, 598.8414, 71.2611,
	// 	-2225.6408, 661.6533, 67.7622);

	// CreateLadder(-2208.4399, 646.6311, 53.9300, 63.7599, 90.7508);

	// DefineWeaponsCachePos(-2211.60791, 1052.62097, 78.99883);
	// DefineWeaponsCachePos(-2197.20264, 969.18610, 78.98930);
	// DefineWeaponsCachePos(-2140.15234, 1218.97644, 46.25816);
	// DefineWeaponsCachePos(-2110.48584, 977.87390, 70.49709);
	// DefineWeaponsCachePos(-2103.68506, 899.04816, 75.69330);
	// DefineWeaponsCachePos(-2234.26538, 584.21545, 50.35577);
	// DefineWeaponsCachePos(-2221.83374, 707.35040, 62.58080);
	// DefineWeaponsCachePos(-2200.90356, 678.93530, 68.23893);
	// DefineWeaponsCachePos(-2164.82495, 686.34259, 88.94374);
	// DefineWeaponsCachePos(-2274.15161, 534.39038, 34.01009);
}
SF_District_City2()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_City2' please wait...");

/*
	LinkTP(
		CreateButton(-1753.70, 883.57, 295.56, "Press ~k~~VEHICLE_ENTER_EXIT~ to enter"),
		CreateButton(-1749.37, 871.82, 25.23, "Press ~k~~VEHICLE_ENTER_EXIT~ to enter"));
*/
	// CreateZipline(
	// 	-2114.91, 923.88, 86.04,
	// 	-1948.34, 952.88, 61.47);
	// CreateZipline(
	// 	-2085.09, 982.10, 80.66,
	// 	-2019.65, 899.83, 62.78);
	// CreateZipline(
	// 	-1754.93, 884.69, 296.37,
	// 	-1989.02, 624.56, 147.52);
	// CreateZipline(
	// 	-1754.93, 884.69, 296.44,
	// 	-1851.00, 1077.59, 150.31);
	// CreateZipline(
	// 	-1753.09, 883.41, 296.08,
	// 	-1748.49, 768.64, 169.70);
	// CreateZipline(
	// 	-1753.09, 883.41, 296.18,
	// 	-1254.30, 953.72, 142.16);

	// DefineWeaponsCachePos(-2046.87012, 463.17310, 34.12703);
	// DefineWeaponsCachePos(-1947.86841, 488.86847, 30.91935);
	// DefineWeaponsCachePos(-1931.62964, 577.71667, 34.13211);
	// DefineWeaponsCachePos(-1951.34485, 718.47125, 45.55853);
	// DefineWeaponsCachePos(-2082.19287, 770.99146, 68.55400);
	// DefineWeaponsCachePos(-2021.50085, 871.65021, 61.63058);
	// DefineWeaponsCachePos(-1988.12134, 896.95831, 44.18531);
	// DefineWeaponsCachePos(-1921.87622, 961.96558, 44.80597);
	// DefineWeaponsCachePos(-2074.21924, 1005.65887, 61.88423);
	// DefineWeaponsCachePos(-1982.39417, 1118.25916, 52.10574);
	// DefineWeaponsCachePos(-2009.34900, 1226.89587, 30.61418);
	// DefineWeaponsCachePos(-1852.08179, 1302.13721, 58.73064);
	// DefineWeaponsCachePos(-1794.35498, 1227.62781, 31.63998);
	// DefineWeaponsCachePos(-1648.44714, 1205.13428, 31.90201);
	// DefineWeaponsCachePos(-1706.03638, 1018.84833, 16.57570);
	// DefineWeaponsCachePos(-1742.83679, 756.27258, 23.87367);
	// DefineWeaponsCachePos(-1630.50244, 669.49847, 6.18189);
	// DefineWeaponsCachePos(-1657.23267, 799.38824, 16.70249);
	// DefineWeaponsCachePos(-1595.26514, 800.79590, 5.80202);
	// DefineWeaponsCachePos(-1754.06091, 959.15283, 23.86285);
	// DefineWeaponsCachePos(-1681.42395, 1109.79700, 53.69134);
	// DefineWeaponsCachePos(-1651.70630, 1210.25659, 12.67112);
	// DefineWeaponsCachePos(-1825.49988, 555.73029, 34.16164);
}
SF_District_Naval()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Naval' please wait...");

	// new buttonid[1];

	// Requires "./scriptfiles/Maps/SF/Naval Base.map" to remove:
	// RemoveBuildingForPlayer(playerid, 968, -1526.4375, 481.3828, 6.9063, 0.01);

	// buttonid[0] = CreateButton(-1520.4270, 482.1193, 7.6727, "Press "KEYTEXT_INTERACT" to activate gate");

	// CreateDoor(968, buttonid,
	// 	-1526.4375, 481.3828, 7.02, 356.8584, 270.00, 0.0,
	// 	-1526.4375, 481.3828, 7.00, 356.8584, 0.0000, 0.0,
	// 	.closedelay = -1, .maxbuttons = 1, .movespeed = 0.01, .movesound = 0, .stopsound = 0);

	CreateStaticLootSpawn(-1346.540039, 492.079986, 10.279999,		GetLootIndexFromName("world_civilian"), 15.0);

	// DefineWeaponsCachePos(-1568.56714, 312.95941, 6.16430);
	// DefineWeaponsCachePos(-1474.82520, 324.02725, 6.13750);
	// DefineWeaponsCachePos(-1333.39526, 373.50836, 6.17051);
	// DefineWeaponsCachePos(-1332.49829, 408.23975, 6.16129);
	// DefineWeaponsCachePos(-1466.05042, 391.89731, 6.17912);
	// DefineWeaponsCachePos(-1465.70007, 353.19241, 6.17956);
	// DefineWeaponsCachePos(-1464.51794, 427.33926, 6.17625);
	// DefineWeaponsCachePos(-1333.34875, 444.43680, 6.16187);
	// DefineWeaponsCachePos(-1257.79797, 501.39343, 17.22221);
	// DefineWeaponsCachePos(-1351.65906, 501.28937, 17.26845);
	// DefineWeaponsCachePos(-1398.96924, 497.37836, 17.22742);
	// DefineWeaponsCachePos(-1443.14771, 494.93771, 17.21759);
	// DefineWeaponsCachePos(-1529.59558, 365.36691, 6.13829);
	// DefineWeaponsCachePos(-1520.81750, 494.38846, 6.17715);
}
SF_District_Police()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Police' please wait...");

	CreateStaticLootSpawn(-1615.52000, 685.33000, 6.48000,			GetLootIndexFromName("world_police"), 10.0);
	CreateStaticLootSpawn(-1590.78000, 716.26000, -6.15000,			GetLootIndexFromName("world_police"), 10.0);
	CreateStaticLootSpawn(-1623.20000, 668.23000, -5.86000,			GetLootIndexFromName("world_police"), 10.0);
	CreateStaticLootSpawn(-1576.75000, 683.36000, 6.33000,			GetLootIndexFromName("world_police"), 10.0);
	CreateStaticLootSpawn(-1670.43000, 696.55000, 29.70000,			GetLootIndexFromName("world_police"), 10.0);
}
SF_District_Industrial()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Industrial' please wait...");

	CreateDynamicObject(2002, -1978.52356, 131.39619, 26.68210, 0.00000, 0.00000, 90.00000);
	// CreateDynamic3DTextLabel("XBOX ONE", YELLOW, -1978.52356, 131.39619, 28.2150, 10.0);
	CreateItem(item_Workbench, -2124.13916, 219.68687, 34.16147, 0.0, 0.0, -128.63998);

	// CreateFuelOutlet(-1679.3594, 403.0547, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1675.2188, 407.1953, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1669.9063, 412.5313, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1665.5234, 416.9141, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1685.9688, 409.6406, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1681.8281, 413.7813, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1676.5156, 419.1172, 6.3828, 2.0, 100.0, frandom(35.0));
	// CreateFuelOutlet(-1672.1328, 423.5000, 6.3828, 2.0, 100.0, frandom(35.0));

	// DefineWeaponsCachePos(-2716.43823, 382.60507, 3.34639);
	// DefineWeaponsCachePos(-2521.67456, 318.69183, 34.09675);
	// DefineWeaponsCachePos(-2473.95605, 401.25406, 26.73841);
	// DefineWeaponsCachePos(-2587.40479, 332.89505, 3.84088);
	// DefineWeaponsCachePos(-2684.57642, 268.28076, 3.31175);
	// DefineWeaponsCachePos(-2641.14673, 190.63800, 3.30231);
	// DefineWeaponsCachePos(-2752.70020, 206.10161, 5.93917);
	// DefineWeaponsCachePos(-2980.13965, 468.74667, 3.87113);
	// DefineWeaponsCachePos(-2755.74316, 96.59800, 6.01551);
	// DefineWeaponsCachePos(-2679.01245, -22.84922, 3.30198);
	// DefineWeaponsCachePos(-2655.62231, 88.49954, 3.07376);
	// DefineWeaponsCachePos(-2524.37085, -7.58145, 24.60770);
	// DefineWeaponsCachePos(-2456.55249, -22.27232, 31.77888);
	// DefineWeaponsCachePos(-2496.17969, 96.59895, 34.15479);
	// DefineWeaponsCachePos(-2311.83350, 196.26547, 34.27616);
	// DefineWeaponsCachePos(-2318.07178, 102.51508, 34.30185);
	// DefineWeaponsCachePos(-2318.58887, -3.95909, 34.31125);
	// DefineWeaponsCachePos(-2351.37231, -146.02968, 34.30040);
	// DefineWeaponsCachePos(-2487.73804, -128.85942, 24.59999);
	// DefineWeaponsCachePos(-2752.04517, -246.72028, 6.17439);
	// DefineWeaponsCachePos(-2898.28613, -35.74038, 3.17566);
	// DefineWeaponsCachePos(-2897.09619, 223.05794, 2.77412);
	// DefineWeaponsCachePos(-2111.67480, -233.74495, 34.29289);
	// DefineWeaponsCachePos(-2124.46118, -126.45124, 34.29319);
	// DefineWeaponsCachePos(-2073.39575, -172.08612, 34.28024);
	// DefineWeaponsCachePos(-2099.70801, -30.01222, 34.27067);
	// DefineWeaponsCachePos(-2047.98547, 13.73487, 34.29177);
	// DefineWeaponsCachePos(-2094.02441, 90.69981, 34.30629);
	// DefineWeaponsCachePos(-2023.68958, 84.27389, 27.12345);
	// DefineWeaponsCachePos(-1939.00598, 145.68996, 25.27828);
	// DefineWeaponsCachePos(-1969.54260, 265.57611, 34.12888);
	// DefineWeaponsCachePos(-2060.09033, 293.43243, 34.33141);
	// DefineWeaponsCachePos(-2130.50269, 222.63608, 35.12024);
	// DefineWeaponsCachePos(-2111.82446, 143.30721, 33.82689);
	// DefineWeaponsCachePos(-2161.18530, 253.25722, 34.31134);
	// DefineWeaponsCachePos(-2234.36841, 306.64288, 34.08678);
	// DefineWeaponsCachePos(-1664.24829, 451.28119, 6.15673);
	// DefineWeaponsCachePos(-1626.63635, 112.75829, -12.12942);
	// DefineWeaponsCachePos(-1561.06958, 96.18565, 2.53192);
	// DefineWeaponsCachePos(-1482.45276, 146.22197, 17.73873);
	// DefineWeaponsCachePos(-1612.43555, 12.42134, 23.14303);
	// DefineWeaponsCachePos(-1582.15430, 64.89886, 16.31585);
	// DefineWeaponsCachePos(-1707.88635, 57.00654, 2.52927);
	// DefineWeaponsCachePos(-1753.44312, -183.35468, 2.47866);
	// DefineWeaponsCachePos(-1745.51611, 158.55383, 2.48789);
	// DefineWeaponsCachePos(-1840.71997, -13.49674, 14.09450);
	// DefineWeaponsCachePos(-1824.40051, -82.25533, 14.09643);
	// DefineWeaponsCachePos(-1862.99194, -142.73291, 10.86462);
	// DefineWeaponsCachePos(-1869.49231, -217.88721, 17.34285);
	// DefineWeaponsCachePos(-1811.91846, -188.73935, 12.41115);

	// CreateHackerTrap(-1844.83752, -101.30441, 4.64848,				GetLootIndexFromName("world_military"));
	// CreateHackerTrap(-1842.06116, -103.07392, 4.64540,				GetLootIndexFromName("world_military"));
	// CreateHackerTrap(-1849.03284, -103.55869, 4.64305,				GetLootIndexFromName("world_military"));
	// CreateHackerTrap(-1848.35547, -98.46133, 4.64475,				GetLootIndexFromName("world_military"));
	// CreateHackerTrap(-1842.68433, -98.32790, 4.64715,				GetLootIndexFromName("world_military"));
}
SF_District_SfAirport()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_SfAirport' please wait...");

	// DefineWeaponsCachePos(-1237.20361, 52.09208, 13.13244);
	// DefineWeaponsCachePos(-1279.19019, 45.46248, 13.13572);
	// DefineWeaponsCachePos(-1199.94641, -132.13683, 13.11613);
	// DefineWeaponsCachePos(-1341.54285, -497.72485, 13.16293);
	// DefineWeaponsCachePos(-1447.83240, -556.44781, 13.16663);
	// DefineWeaponsCachePos(-1671.28918, -628.41888, 13.09485);
	// DefineWeaponsCachePos(-1416.39600, -297.07736, 13.13366);
	// DefineWeaponsCachePos(-1545.16748, -440.26828, 4.98256);
	// DefineWeaponsCachePos(-1735.94885, -567.59247, 15.47855);
	// DefineWeaponsCachePos(-1528.37463, -260.38547, 13.09692);
	// DefineWeaponsCachePos(-1371.29199, -384.41708, 13.13528);

	// CreateHackerTrap(1229.78259, 53.58940, 13.23220,				GetLootIndexFromName("world_police"));
	// CreateHackerTrap(-1542.14001, -443.55999, 5.19000,				GetLootIndexFromName("world_police"));
}
SF_District_MontFoster()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_MontFoster' please wait...");

	// DefineWeaponsCachePos(-2150.16040, -408.60284, 34.30775);
	// DefineWeaponsCachePos(-1986.81006, -497.92313, 34.31303);
	// DefineWeaponsCachePos(-2555.83960, -251.85573, 20.41562);
	// DefineWeaponsCachePos(-2614.35718, -305.86423, 21.81332);
	// DefineWeaponsCachePos(-2515.93628, -248.72455, 37.54561);
	// DefineWeaponsCachePos(-2417.03809, -230.64073, 39.51999);
	// DefineWeaponsCachePos(-2296.50806, -260.05917, 42.32588);
	// DefineWeaponsCachePos(-2424.78906, -304.97256, 56.97111);
	// DefineWeaponsCachePos(-2518.56592, -343.68137, 57.11472);
	// DefineWeaponsCachePos(-2304.42700, -342.69180, 64.54024);
	// DefineWeaponsCachePos(-2342.75513, -359.71954, 67.41110);
	// DefineWeaponsCachePos(-2387.56665, -577.08984, 131.10046);
	// DefineWeaponsCachePos(-2518.69678, -596.86841, 131.70680);
	// DefineWeaponsCachePos(-2050.66992, -853.88745, 31.16034);
	// DefineWeaponsCachePos(-1997.96411, -967.32709, 31.15343);
	// DefineWeaponsCachePos(-1949.76208, -841.21948, 34.88272);
	// DefineWeaponsCachePos(-2000.53369, -971.46515, 31.11395);
	// DefineWeaponsCachePos(-1893.49109, -858.82703, 31.01959);
}
SF_District_Ship1()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Ship1' please wait...");
}
SF_District_Ship2()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'SF_District_Ship2' please wait...");
}
