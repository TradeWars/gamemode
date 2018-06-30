Load_FC()
{
	CreateFuelOutlet(-2246.7031, -2559.7109, 31.0625, 2.0, 100.0, frandom(50.0));
	CreateFuelOutlet(-2241.7188, -2562.2891, 31.0625, 2.0, 100.0, frandom(50.0));

	CreateFuelOutlet(-1600.6719, -2707.8047, 47.9297, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1603.9922, -2712.2031, 47.9297, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1607.3047, -2716.6016, 47.9297, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1610.6172, -2721.0000, 47.9297, 2.0, 100.0, frandom(40.0));

	CreateFuelOutlet(-85.2422, -1165.0313, 2.6328, 2.0, 130.0, frandom(40.0));
	CreateFuelOutlet(-90.1406, -1176.6250, 2.6328, 2.0, 130.0, frandom(40.0));
	CreateFuelOutlet(-92.1016, -1161.7891, 2.9609, 2.0, 130.0, frandom(40.0));
	CreateFuelOutlet(-97.0703, -1173.7500, 3.0313, 2.0, 130.0, frandom(40.0));


	CreateLadder(-1056.0153, -628.1323, 32.0012, 130.1213, 180.0);
	CreateLadder(-1059.8658, -617.5842, 34.0942, 130.1221, 270.0);
	CreateLadder(-1073.3224, -645.8720, 32.0078, 56.6255, 180.0);
	CreateLadder(-1111.0469, -645.8738, 32.0078, 56.6202, 180.0);
	CreateLadder(-1097.3682, -640.2991, 34.0896, 44.2146, 0.0);
	CreateLadder(-1063.1298, -640.0430, 34.0896, 44.2146, 0.0);
	CreateLadder(-1099.8262, -719.3637, 32.0078, 54.7115, 180.0);
	CreateLadder(-1055.5986, -719.3712, 32.0078, 54.7115, 180.0);
	CreateLadder(-1013.4467, -719.3651, 32.0078, 54.7115, 180.0);

	FC_District_Chilliad();
	FC_District_AngelPine();
	FC_District_Scrapyard();
	FC_District_Farms();
	FC_District_EasterChem();
	FC_District_FallenTree();
	FC_District_FlintGen();

	DefineSupplyDropPos("Back-o-Beyond", -638.19598, -2442.45068, 30.10299);
	DefineSupplyDropPos("Flint Range", -519.18439, -1633.60962, 8.71135);
	DefineSupplyDropPos("Flint County Fallen Tree", -587.47852, -484.26419, 24.47583);
	DefineSupplyDropPos("The Farm Flint County", -1114.30457, -974.00067, 128.16339);
	DefineSupplyDropPos("Angel Pine", -2165.39160, -2395.42017, 29.44930);
	DefineSupplyDropPos("Mount Chilliad", -2335.43652, -1652.50720, 482.67642);
}


FC_District_Chilliad()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_Chilliad' please wait...");
}

FC_District_AngelPine()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_AngelPine' please wait...");

	CreateItem(item_Workbench, -2176.33765, -2536.95630, 29.59808, 0.0, 0.0, -219.05981);
}

FC_District_Scrapyard()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_Scrapyard' please wait...");

	CreateItem(item_ScrapMachine, -1888.26416, -1636.40588, 21.21387, 0.0, 0.0, 0.0);
	CreateItem(item_RefineMachine, -1848.56006, -1685.39380, 22.97520, 0.0, 0.0, -54.0);
}

FC_District_Farms()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_Farms' please wait...");

	CreateItem(item_Workbench, -392.98178, -1433.41199, 24.67424, 0.0, 0.0, 0.00000);
	CreateItem(item_Workbench, -372.71423, -1040.36572, 58.21876, 0.0, 0.0, 95.58000);

	CreateHackerTrap(-362.127227, -1060.984008, 58.241569,			GetLootIndexFromName("world_survivor"));
}

FC_District_EasterChem()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_EasterChem' please wait...");
}

FC_District_FallenTree()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_FallenTree' please wait...");
}

FC_District_FlintGen()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'FC_District_FlintGen' please wait...");
}
