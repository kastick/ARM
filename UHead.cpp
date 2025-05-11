//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFHead *FHead;
//---------------------------------------------------------------------------
__fastcall TFHead::TFHead(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFHead::FormShow(TObject *Sender)
{
    ProgressBar1->Position = 0; // Сброс прогресс-бара
    Timer1->Enabled = true; // Включаем таймер
}
//---------------------------------------------------------------------------
void __fastcall TFHead::Timer1Timer(TObject *Sender)
{
    // Увеличиваем позицию прогресс-бара
    if (ProgressBar1->Position < ProgressBar1->Max) {
        ProgressBar1->Position += 100; // Увеличиваем на 5 (или любое другое значение)
    } else {
        Timer1->Enabled = false; // Останавливаем таймер, когда прогресс завершен
        this->Close(); // Закрываем форму
    }
}
//---------------------------------------------------------------------------
