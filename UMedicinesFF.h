//---------------------------------------------------------------------------

#ifndef UMedicinesFFH
#define UMedicinesFFH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFMedicinesFF : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TButton *Button1;
	TButton *Button2;
	TPanel *Panel1;
	TImage *Image1;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit4;
	TDBLookupComboBox *DBLookupComboBox1;
	TDBEdit *DBEdit3;
	TDBCheckBox *DBCheckBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFMedicinesFF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMedicinesFF *FMedicinesFF;
//---------------------------------------------------------------------------
#endif
