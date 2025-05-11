//---------------------------------------------------------------------------
//#define DEBUG

#include <vcl.h>
#pragma hdrstop
#include <System.SysUtils.hpp>

#include <map>

#include "UCoupons.h"
#include "UCardEntry.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFCoupons *FCoupons;
//---------------------------------------------------------------------------
__fastcall TFCoupons::TFCoupons(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFCoupons::FormCreate(TObject *Sender)
{
    // Открываем запрос для получения врачей из таблицы Document
    DataModule2->FDQuery3->SQL->Clear();
    DataModule2->FDQuery3->SQL->Add(
		"SELECT DocID, "
	    "(Select Specialties from Specialties where SpecID = Document.Specialties) as Specialties, "
        "(name + ' ' + surname + ' ' + patronymic) as name "
        "FROM Document "
        "WHERE DocID IN (SELECT KliID FROM Klients WHERE employee = true)"
    );
    DataModule2->FDQuery3->Open();

    // Создаем временную структуру для хранения узлов по специальностям
    std::map<String, TTreeNode*> specialtyNodes;

    // Проходим по всем записям врачей
    while (!DataModule2->FDQuery3->Eof)
    {
        String specialty = DataModule2->FDQuery3->FieldByName("Specialties")->AsString;
        String doctorName = DataModule2->FDQuery3->FieldByName("name")->AsString;
        int docID = DataModule2->FDQuery3->FieldByName("DocID")->AsInteger;

        // Проверяем, существует ли уже корневой узел для данной специальности
        TTreeNode *specialtyNode;
        if (specialtyNodes.find(specialty) == specialtyNodes.end())
        {
            // Если узел не существует, создаем новый корневой узел
            specialtyNode = TreeView1->Items->Add(nullptr, specialty);
            specialtyNodes[specialty] = specialtyNode; // Сохраняем узел в структуре
        }
        else
        {
            // Если узел уже существует, получаем его
            specialtyNode = specialtyNodes[specialty];
        }

        // Добавляем врача как дочерний узел к корневому узлу специальности
        TTreeNode *doctorNode = TreeView1->Items->AddChild(specialtyNode, doctorName);
        doctorNode->Data = reinterpret_cast<void*>(docID);

        // Переходим к следующему врачу
        DataModule2->FDQuery3->Next();
    }

    // Закрываем запрос после использования
    DataModule2->FDQuery3->Close();

    TreeView1->Selected = nullptr;

    Memo1->Visible = false;
    #ifdef DEBUG
        Memo1->Visible = true;
	#endif
}
//---------------------------------------------------------------------------


///////////////////////////////// ==Фильтры== ///////////////////////////////
void __fastcall TFCoupons::TreeView1Click(TObject *Sender)
{
	 ApplyFilters();

	 TTreeNode *selectedNode = TreeView1->Selected;
	 SelectedDoctorID = selectedNode->Data ? reinterpret_cast<int>(selectedNode->Data) : -1;

	 #ifdef DEBUG
		Memo1->Lines->Add("\nТекущий врач: " + IntToStr(SelectedDoctorID));
	 #endif
}

void __fastcall TFCoupons::MonthCalendar1Click(TObject *Sender)
{
    ApplyFilters(); // Применяем фильтры при выборе даты
}

void __fastcall TFCoupons::CheckBox1Click(TObject *Sender)
{
	ApplyFilters();
}

void __fastcall TFCoupons::ApplyFilters()
{
// Закрываем текущий запрос
    DataModule2->FDQuery1->Close();

    // Устанавливаем фильтр для FDQuery
    DataModule2->FDQuery1->Filtered = false; // Сначала отключаем фильтрацию

    // Формируем фильтр
    String filter = "";

    // Получаем выбранный узел
    TTreeNode *selectedNode = TreeView1->Selected;
    String doctorFullName;

    // Проверяем, что выбранный узел не является корневым узлом
    if (selectedNode != nullptr && selectedNode->Parent != nullptr)
    {
        // Получаем полное имя врача из текста узла
        doctorFullName = selectedNode->Text;
    }

    // Проверяем, выбрана ли дата
	bool hasDateFilter = MonthCalendar1->Date != TDate(0); // Проверяем, выбрана ли дата
	String dateFilter = "Дата = '" + FormatDateTime("dd.mm.yyyy", MonthCalendar1->Date) + "'";

    // Добавляем фильтр по врачу, если он выбран
    if (doctorFullName.Length() > 0) {
        filter += "ФИО_Врача LIKE '" + doctorFullName + "%'";
    }

    // Добавляем фильтр по дате, если она выбрана
    if (hasDateFilter) {
        if (filter.Length() > 0) {
            filter += " AND "; // Если есть фильтр по врачу, добавляем AND
        }
        filter += dateFilter; // Добавляем фильтр по дате
    }

	// Добавляем фильтр по статусу в зависимости от состояния чекбокса
    if (CheckBox1->Checked) {
        // Если чекбокс установлен, фильтруем по status = true
        if (filter.Length() > 0) {
            filter += " AND "; // Если есть другие фильтры, добавляем AND
        }
        filter += "status = true"; // Фильтр по статусу
    } else {
        // Если чекбокс не установлен, фильтруем по status = false
        if (filter.Length() > 0) {
            filter += " AND "; // Если есть другие фильтры, добавляем AND
        }
        filter += "status = false"; // Фильтр по статусу
    }

    // Устанавливаем фильтр, если он не пустой
    if (filter.Length() > 0) {
        DataModule2->FDQuery1->Filter = filter;
        DataModule2->FDQuery1->Filtered = true; // Включаем фильтрацию
    } else {
        DataModule2->FDQuery1->Filtered = false; // Если фильтр пустой, отключаем фильтрацию
    }

    // Открываем запрос
	DataModule2->FDQuery1->Open();

    StatusBar1->Panels->Items[0]->Text = "Количество записей: " + IntToStr(DataModule2->FDQuery1->RecordCount);
	#ifdef DEBUG
		// Отладка: выводим фильтр в Memo
		Memo1->Lines->Add("Текущий фильтр: " + filter);
    #endif
}
/////////////////////////////////////////////////////////////////////////////

void __fastcall TFCoupons::Button1Click(TObject *Sender)
{
	int selectedRecID = DataModule2->FDQuery1->FieldByName("RecID")->AsInteger;
	int selectedDocID = DataModule2->FDQuery1->FieldByName("DoctorID")->AsInteger;

	#ifdef DEBUG
		// Отладка: выводим фильтр в Memo
		Memo1->Lines->Add("Текущий DocID: " + IntToStr(selectedDocID));
		Memo1->Lines->Add("Текущий RecID: " + IntToStr(selectedRecID));
	#endif

	FCardEntry->DocID(selectedDocID);
	FCardEntry->SetRecID(selectedRecID);

	FCardEntry->ViewHide();

	FCardEntry->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFCoupons::Button3Click(TObject *Sender)
{
	DataModule2->FDTransaction1->StartTransaction();
	TDateTime selectedDate = MonthCalendar1->Date;

    #ifdef DEBUG
		// Отладка: выводим фильтр в Memo
		Memo1->Lines->Add("Текущий RecID: " + IntToStr(selectedRecID));
	#endif

	FCardEntry->SetDoctorID(SelectedDoctorID, selectedDate); // Вызываем метод для установки DocID

	FCardEntry->AddHide();

	FCardEntry->ShowModal();
}
//---------------------------------------------------------------------------



void __fastcall TFCoupons::Button2Click(TObject *Sender)
{
    DataModule2->FDQuery1->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TFCoupons::FormShow(TObject *Sender)
{
    StatusBar1->Panels->Items[0]->Text = "Количество записей: " + IntToStr(DataModule2->FDQuery1->RecordCount);
}
//---------------------------------------------------------------------------

