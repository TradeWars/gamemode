Load_RC()
{
	CreateFuelOutlet(1378.96094, 461.03906, 19.32813, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(1380.63281, 460.27344, 19.32813, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(1383.39844, 459.07031, 19.32813, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(1385.07813, 458.29688, 19.32813, 2.0, 100.0, frandom(40.0));

	CreateFuelOutlet(655.66406, -558.92969, 15.35938, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(655.66406, -560.54688, 15.35938, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(655.66406, -569.60156, 15.35938, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(655.66406, -571.21094, 15.35938, 2.0, 100.0, frandom(40.0));

	RC_District_LogCamp();
	RC_District_BlueberryAcres();
	RC_District_BlueberryTown();
	RC_District_Dillmore();
	RC_District_Montgomery();
	RC_District_Palomino();
	RC_District_RedGen();

	DefineSupplyDropPos("Fisher's Lagoon", 1906.07385, -501.28192, 16.93526);
	DefineSupplyDropPos("Montgomery", 1332.75269, 346.71506, 18.34710);
	DefineSupplyDropPos("Dillimore", 642.83069, -594.28088, 15.15962);
	DefineSupplyDropPos("Blueberry", 204.94981, -261.21274, 0.52650);
}


RC_District_LogCamp()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_LogCamp' please wait...");
}

RC_District_BlueberryAcres()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_BlueberryAcres' please wait...");

	CreateItem(item_Workbench, 94.44927, -168.05229, 1.55108, 0.0, 0.0, -180.77998);
}

RC_District_BlueberryTown()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_BlueberryTown' please wait...");
}

RC_District_Dillmore()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_Dillmore' please wait...");
}

RC_District_Montgomery()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_Montgomery' please wait...");
}

RC_District_Palomino()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_Palomino' please wait...");

	CreateItem(item_Workbench, 2560.82031, 73.39390, 25.42815, 0.0, 0.0, 0.00000);
}

RC_District_RedGen()
{
	ChatMsgAll(YELLOW, " >  Loading world region: 'RC_District_RedGen' please wait...");
}
