//---------------------------------------------------------------------------

#ifndef UCountriesH
#define UCountriesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFCountries : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TPanel *Panel1;
	TStatusBar *StatusBar1;
	TButton *Button1;
	TEdit *Edit1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFCountries(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCountries *FCountries;
//---------------------------------------------------------------------------
#endif
