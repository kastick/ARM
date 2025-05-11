//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPositionsFF.h"
#include "UPositions.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPositionsFF *FPositionsFF;
//---------------------------------------------------------------------------
__fastcall TFPositionsFF::TFPositionsFF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPositionsFF::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

	DataModule2->FDQuery10->Edit();
	DataModule2->FDQuery10->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------
void __fastcall TFPositionsFF::Button2Click(TObject *Sender)
{
    // Проверяем, является ли запись новой
	if (DataModule2->FDQuery10->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
			DataModule2->FDQuery10->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
		DataModule2->FDQuery10->Cancel();
    }

    // Закрываем форму
    this->Close();
}
//---------------------------------------------------------------------------
