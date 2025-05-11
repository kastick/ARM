//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UPatients.cpp", FPatients);
USEFORM("UPatientsView.cpp", FPatientsView);
USEFORM("UPositions.cpp", FPositions);
USEFORM("UMedicinesFF.cpp", FMedicinesFF);
USEFORM("UMedicinesGroups.cpp", FMedicinesGroups);
USEFORM("UMedicinesGroupsFF.cpp", FMedicinesGroupsFF);
USEFORM("URegionsFF.cpp", FRegionsFF);
USEFORM("UServicesDirectory.cpp", FServicesDirectory);
USEFORM("UServicesFF.cpp", FServicesFF);
USEFORM("UPositionsFF.cpp", FPositionsFF);
USEFORM("UPrompt.cpp", FPrompt);
USEFORM("URegions.cpp", FRegions);
USEFORM("UMedicines.cpp", FMedicines);
USEFORM("UCardEntry.cpp", FCardEntry);
USEFORM("UCiphersMKB.cpp", FCiphersMKB);
USEFORM("DataModule.cpp", DataModule2); /* TDataModule: File Type */
USEFORM("UCoupons.cpp", FCoupons);
USEFORM("UHead.cpp", FHead);
USEFORM("UMain.cpp", FMain);
USEFORM("UCiphersMKBFF.cpp", FCiphersMKBFF);
USEFORM("UCountries.cpp", FCountries);
USEFORM("UCountriesFF.cpp", FCountriesFF);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
        Application->CreateForm(__classid(TFPrompt), &FPrompt);
		Application->CreateForm(__classid(TFMain), &FMain);
		Application->CreateForm(__classid(TDataModule2), &DataModule2);
		Application->CreateForm(__classid(TFPatients), &FPatients);
		Application->CreateForm(__classid(TFCoupons), &FCoupons);
		Application->CreateForm(__classid(TFPatientsView), &FPatientsView);
		Application->CreateForm(__classid(TFCardEntry), &FCardEntry);
		Application->CreateForm(__classid(TFServicesDirectory), &FServicesDirectory);
		Application->CreateForm(__classid(TFServicesFF), &FServicesFF);
		Application->CreateForm(__classid(TFCountries), &FCountries);
		Application->CreateForm(__classid(TFCountriesFF), &FCountriesFF);
		Application->CreateForm(__classid(TFRegions), &FRegions);
		Application->CreateForm(__classid(TFRegionsFF), &FRegionsFF);
		Application->CreateForm(__classid(TFPositions), &FPositions);
		Application->CreateForm(__classid(TFPositionsFF), &FPositionsFF);
		Application->CreateForm(__classid(TFMedicines), &FMedicines);
		Application->CreateForm(__classid(TFCiphersMKB), &FCiphersMKB);
		Application->CreateForm(__classid(TFMedicinesFF), &FMedicinesFF);
		Application->CreateForm(__classid(TFCiphersMKBFF), &FCiphersMKBFF);
		Application->CreateForm(__classid(TFMedicinesGroups), &FMedicinesGroups);
		Application->CreateForm(__classid(TFMedicinesGroupsFF), &FMedicinesGroupsFF);
		Application->CreateForm(__classid(TFHead), &FHead);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
