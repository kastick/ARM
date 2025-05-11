//---------------------------------------------------------------------------

#ifndef UHeadH
#define UHeadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFHead : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFHead(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFHead *FHead;
//---------------------------------------------------------------------------
#endif
