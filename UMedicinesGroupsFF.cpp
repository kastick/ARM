//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMedicinesGroupsFF.h"
#include "UMedicinesGroups.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMedicinesGroupsFF *FMedicinesGroupsFF;
//---------------------------------------------------------------------------
__fastcall TFMedicinesGroupsFF::TFMedicinesGroupsFF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFMedicinesGroupsFF::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

	DataModule2->FDQuery16->Edit();
	DataModule2->FDQuery16->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------
void __fastcall TFMedicinesGroupsFF::Button2Click(TObject *Sender)
{
    // Проверяем, является ли запись новой
	if (DataModule2->FDQuery16->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
			DataModule2->FDQuery16->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
		DataModule2->FDQuery16->Cancel();
    }

    // Закрываем форму
	this->Close();
}
//---------------------------------------------------------------------------
