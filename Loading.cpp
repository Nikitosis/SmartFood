//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Loading.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm12::OpenLoading(int maximum)
{
  Form12->Show();
  ProgressBar1->Position=0;
  ProgressBar1->Max=maximum;
  Label1->Caption="���� �������������";
  Application->ProcessMessages();
}
//--------------------------------------------------------------------------
void __fastcall TForm12::AddProgress()
{
  ProgressBar1->Position++;
}
//--------------------------------------------------------------------------
void __fastcall TForm12::OpenSaving(int maximum)
{
  Form12->Show();
  ProgressBar1->Position=0;
  ProgressBar1->Max=maximum;
  Label1->Caption="���� ����������";
  Application->ProcessMessages();
}