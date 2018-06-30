Load_TR()
{
	CreateFuelOutlet(-1465.4766, 1868.2734, 32.8203, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1464.9375, 1860.5625, 32.8203, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1477.8516, 1867.3125, 32.8203, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1477.6563, 1859.7344, 32.8203, 2.0, 100.0, frandom(40.0));

	CreateFuelOutlet(-1327.0313, 2685.5938, 50.4531, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1327.7969, 2680.1250, 50.4531, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1328.5859, 2674.7109, 50.4531, 2.0, 100.0, frandom(40.0));
	CreateFuelOutlet(-1329.2031, 2669.2813, 50.4531, 2.0, 100.0, frandom(40.0));

	TR_District_Bayside();
	TR_District_Quebrados();
	TR_District_Barancas();
	TR_District_Sherman();
	TR_District_RobadaGen();

	DefineSupplyDropPos("Tierra Robada South", -720.72766, 972.52899, 11.04721);
	DefineSupplyDropPos("Tierra Robada Midland", -1484.86084, 1977.28833, 46.76990);
	DefineSupplyDropPos("Tierra Robada North Freeway", -2547.67798, 2614.91919, 59.90747);
}


TR_District_Bayside()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'TR_District_Bayside' please wait...");
}


TR_District_Quebrados()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'TR_District_Quebrados' please wait...");
}

TR_District_Barancas()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'TR_District_Barancas' please wait...");
}

TR_District_Sherman()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'TR_District_Sherman' please wait...");
}

TR_District_RobadaGen()
{
	// ChatMsgAll(YELLOW, " >  Loading world region: 'TR_District_RobadaGen' please wait...");

	CreateItem(item_Workbench, -1513.53040, 1978.50232, 47.35660, 0.0, 0.0, 85.37996);
}
