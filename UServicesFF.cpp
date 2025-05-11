//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UServicesFF.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFServicesFF *FServicesFF;
//---------------------------------------------------------------------------
__fastcall TFServicesFF::TFServicesFF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFServicesFF::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

   	DataModule2->FDQuery7->Edit();
	DataModule2->FDQuery7->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------
void __fastcall TFServicesFF::Button2Click(TObject *Sender)
{
	// Проверяем, является ли запись новой
    if (DataModule2->FDQuery7->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
            DataModule2->FDQuery7->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
        DataModule2->FDQuery7->Cancel();
    }

    // Закрываем форму
    this->Close();
}
//---------------------------------------------------------------------------
