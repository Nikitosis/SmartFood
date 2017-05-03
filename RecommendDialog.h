//---------------------------------------------------------------------------

#ifndef RecommendDialogH
#define RecommendDialogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
double BMR;
TEdit *LWeights[100];
TLabel *LBel[100];
TLabel *LZh[100];
TLabel *LUgl[100];
TLabel *LKal[100];
	__fastcall TForm8(TComponent* Owner);
	void __fastcall TForm8::MassChange(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
