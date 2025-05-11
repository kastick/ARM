//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCiphersMKBFF.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFCiphersMKBFF *FCiphersMKBFF;
//---------------------------------------------------------------------------
__fastcall TFCiphersMKBFF::TFCiphersMKBFF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFCiphersMKBFF::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

	DataModule2->FDQuery14->Edit();
	DataModule2->FDQuery14->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------
void __fastcall TFCiphersMKBFF::Button2Click(TObject *Sender)
{
    // Проверяем, является ли запись новой
	if (DataModule2->FDQuery14->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
			DataModule2->FDQuery14->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
		DataModule2->FDQuery14->Cancel();
    }

    // Закрываем форму
	this->Close();
}
//---------------------------------------------------------------------------
