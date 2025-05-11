//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPatientsView.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPatientsView *FPatientsView;
//---------------------------------------------------------------------------
__fastcall TFPatientsView::TFPatientsView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFPatientsView::Button2Click(TObject *Sender)
{
    // Проверяем, является ли запись новой
	if (DataModule2->FDQuery2->State == dsInsert)
    {
        // Откатываем изменения, если транзакция активна
        if (DataModule2->FDTransaction1->Active)
        {
			DataModule2->FDTransaction1->Rollback();
			DataModule2->FDQuery2->Delete();
            ShowMessage("Новая запись отменена.");
        }
    }
    else
    {
        // Если запись уже существует, можно просто отменить изменения
		DataModule2->FDQuery2->Cancel();
    }

    // Закрываем форму
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFPatientsView::Button1Click(TObject *Sender)
{
    if (!DataModule2->FDTransaction1->Active)
    {
		DataModule2->FDTransaction1->StartTransaction();
    }

	DataModule2->FDQuery2->Edit();
	DataModule2->FDQuery2->Post();

	DataModule2->FDTransaction1->Commit();
}
//---------------------------------------------------------------------------

void __fastcall TFPatientsView::SetPatiID(int patiID)
{
	this->patiID = patiID;
}

void __fastcall TFPatientsView::Button4Click(TObject *Sender)
{
	DataModule2->FDQuery18->Close();
	DataModule2->FDQuery18->ParamByName("KliID")->AsInteger = patiID;
	DataModule2->FDQuery18->Open();
	DataModule2->frxReport3->ShowReport();
}
//---------------------------------------------------------------------------




