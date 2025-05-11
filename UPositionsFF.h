//---------------------------------------------------------------------------

#ifndef UPositionsFFH
#define UPositionsFFH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TFPositionsFF : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image1;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFPositionsFF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPositionsFF *FPositionsFF;
//---------------------------------------------------------------------------
#endif
