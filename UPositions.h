//---------------------------------------------------------------------------

#ifndef UPositionsH
#define UPositionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFPositions : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TEdit *Edit1;
	TButton *Button2;
	TButton *Button3;
	TDBGrid *DBGrid1;
	TStatusBar *StatusBar1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFPositions(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPositions *FPositions;
//---------------------------------------------------------------------------
#endif
