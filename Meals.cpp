//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "MealsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void AddLeft(int num)
{
	Form3->ProductsHave++;
	int n=Form3->ProductsHave-1;
	int k=Form6->ScrollBox1->VertScrollBar->Position;  //����� �����������,����� �����. ��������
	Form6->ScrollBox1->VertScrollBar->Position=0;

	int w=Form6->ScrollBox1->Width/4;
	//w=round(w);

	Form3->PanelsHave[n]=new TPanel(Form6);
	Form3->PanelsHave[n]->Parent=Form6->ScrollBox1;
	Form3->PanelsHave[n]->Top=Form3->PanelHaveH*(Form3->ProductsHave-1);
	Form3->PanelsHave[n]->Height=Form3->PanelHaveH;
	Form3->PanelsHave[n]->Width=Form6->ScrollBox1->Width-4;

	Form3->LabelesHave[n]=new TLabel(Form6);
	Form3->LabelesHave[n]->Parent=Form3->PanelsHave[n];
	Form3->LabelesHave[n]->Top=15;
	Form3->LabelesHave[n]->Left=15;
	Form3->LabelesHave[n]->Caption=Form2->Labeles[num*5]->Caption;
	Form3->LabelesHave[n]->Width=w;

	Form3->ImagesHave[n]=new TImage(Form6);
	Form3->ImagesHave[n]->Parent=Form3->PanelsHave[n];
	Form3->ImagesHave[n]->Left=10+w;
	Form3->ImagesHave[n]->Width=w;
	Form3->ImagesHave[n]->Height=46;
	Form3->ImagesHave[n]->Stretch=true;
	Form3->ImagesHave[n]->Picture=Form2->Images[num]->Picture;

	Form3->EditsHave[n]=new TEdit(Form6);
	Form3->EditsHave[n]->Parent=Form3->PanelsHave[n];
	Form3->EditsHave[n]->Left=15+2*w;
	Form3->EditsHave[n]->Top=15;
	Form3->EditsHave[n]->Width=w;

	Form3->ButtonsHave[n]=new TButton(Form6);
	Form3->ButtonsHave[n]->Parent=Form3->PanelsHave[n];
	Form3->ButtonsHave[n]->Left=15+3*w;
	Form3->ButtonsHave[n]->Width=w-20;
	Form3->ButtonsHave[n]->Height=Form3->PanelHaveH;

	Form6->ScrollBox1->VertScrollBar->Position=k;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
PanelH=100;
Form6->Show();
int m=Form2->ProductsA;
PanelHaveH=50;
for(int i=0;i<Form2->ProductsA;i++)
if(Form2->IsDel[i]==false)
   AddLeft(i);

}
//---------------------------------------------------------------------------

