//---------------------------------------------------------------------------

#ifndef MealsFormH
#define MealsFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox2;
	TLabel *Label3;
	TLabel *Label4;
	TOpenPictureDialog *OpenPictureDialog1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TButton *Button5;
	TPanel *Panel1;
	TPanel *Panel2;
	TImage *Image2;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *Button2;
	TBitBtn *Button3;
	TBitBtn *Button4;
	TBitBtn *Button1;
	TImage *Image3;
	TImage *Image4;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Panel1MouseEnter(TObject *Sender);
	void __fastcall Panel2MouseEnter(TObject *Sender);
	void __fastcall FormMouseEnter(TObject *Sender);
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SettingsEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
bool onScroll1,onScroll2;
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
