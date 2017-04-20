//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecommendDialog.h"
#include "Meals.h"
#include "MealsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
Form3->IsRecommend=true;
Form3->ShowModal();
for(int i=0;i<Form3->MealsA;i++)
	{
		if(Form3->IsDelMeal[i]==false)
		{
			Form3->RecomPanel[i]->Height=10;
			int kal=StrToInt(Form3->Labeles[i*5+4]->Caption);

			if(BMR-kal>400)   //���� ������
				Form3->RecomPanel[i]->Color=clHighlight;
				else
				if(BMR-kal<-400)  //���� ������
					Form3->RecomPanel[i]->Color=RGB(247,192,25);
					else
					Form3->RecomPanel[i]->Color=RGB(25,247,83);     //���� ��������
		}
    }
}
//---------------------------------------------------------------------------
