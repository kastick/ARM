//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCountriesFF.h"
#include "UCountries.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFCountriesFF *FCountriesFF;
//---------------------------------------------------------------------------
__fastcall TFCountriesFF::TFCountriesFF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFCountriesFF::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

	DataModule2->FDQuery8->Edit();
	DataModule2->FDQuery8->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------
void __fastcall TFCountriesFF::Button2Click(TObject *Sender)
{
    // Проверяем, является ли запись новой
	if (DataModule2->FDQuery8->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
			DataModule2->FDQuery8->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
		DataModule2->FDQuery8->Cancel();
    }

    // Закрываем форму
    this->Close();
}
//---------------------------------------------------------------------------
