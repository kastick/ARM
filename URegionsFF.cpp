//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URegionsFF.h"
#include "URegions.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRegionsFF *FRegionsFF;
//---------------------------------------------------------------------------
__fastcall TFRegionsFF::TFRegionsFF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFRegionsFF::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

	DataModule2->FDQuery9->Edit();
	DataModule2->FDQuery9->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------
void __fastcall TFRegionsFF::Button2Click(TObject *Sender)
{
    // Проверяем, является ли запись новой
	if (DataModule2->FDQuery9->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
			DataModule2->FDQuery9->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
		DataModule2->FDQuery9->Cancel();
    }

    // Закрываем форму
    this->Close();
}
//---------------------------------------------------------------------------
