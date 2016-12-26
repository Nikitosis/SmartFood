// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "MealsForm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
	memset(IsLeft, false, 10000 * sizeof(bool));
	memset(IsRight, false, 10000 * sizeof(bool));
}

// ---------------------------------------------------------------------------
void AddLeft(int num) {
	Form3->ProductsHave++;
	int n = Form3->ProductsHave - 1;
	int k = Form6->ScrollBox1->VertScrollBar->Position;
	Form6->ScrollBox1->VertScrollBar->Position = 0;

	int w = Form6->ScrollBox1->Width / 4;
	// w=round(w);

	Form3->PanelsHave[n] = new TPanel(Form6);
	Form3->PanelsHave[n]->Parent = Form6->ScrollBox1;
	Form3->PanelsHave[n]->Top = Form3->PanelHaveH * (Form3->ProductsHave - 1);
	Form3->PanelsHave[n]->Height = Form3->PanelHaveH;
	Form3->PanelsHave[n]->Width = Form6->ScrollBox1->Width - 4;

	Form3->LabelesHave[n] = new TLabel(Form6);
	Form3->LabelesHave[n]->Parent = Form3->PanelsHave[n];
	Form3->LabelesHave[n]->Top = 15;
	Form3->LabelesHave[n]->Left = 15;
	Form3->LabelesHave[n]->Caption = Form2->Labeles[num * 5]->Caption;
	Form3->LabelesHave[n]->Width = w;

	Form3->ImagesHave[n] = new TImage(Form6);
	Form3->ImagesHave[n]->Parent = Form3->PanelsHave[n];
	Form3->ImagesHave[n]->Left = 10 + w;
	Form3->ImagesHave[n]->Width = w;
	Form3->ImagesHave[n]->Height = 46;
	Form3->ImagesHave[n]->Stretch = true;
	Form3->ImagesHave[n]->Picture = Form2->Images[num]->Picture;

	Form3->EditsHave[n] = new TEdit(Form6);
	Form3->EditsHave[n]->Parent = Form3->PanelsHave[n];
	Form3->EditsHave[n]->Left = 15 + 2 * w;
	Form3->EditsHave[n]->Top = 15;
	Form3->EditsHave[n]->Width = w;

	Form3->ButtonsHave[n] = new TButton(Form6);
	Form3->ButtonsHave[n]->Parent = Form3->PanelsHave[n];
	Form3->ButtonsHave[n]->Left = 15 + 3 * w;
	Form3->ButtonsHave[n]->Width = w - 20;
	Form3->ButtonsHave[n]->Height = Form3->PanelHaveH;
	Form3->ButtonsHave[n]->Tag = n;
	Form3->ButtonsHave[n]->OnClick=Form3->AddClick;

	Form6->ScrollBox1->VertScrollBar->Position = k;
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender) {
	for (int i = 0; i < ProductsHave+ProductsUse; i++)
		PanelsHave[i]->Free();
	ProductsHave = 0;
	ProductsUse = 0;
	PanelHaveH = 50;
	PropNum=-1;
	PanelH = 100;
	Form6->Show();
	int m = Form2->ProductsA;
	for(int i=0;i<Form2->ProductsA;i++)
	{
		IsLeft[-1][i]=false;
		IsRight[-1][i]=false;
    }
	for (int i = 0; i < Form2->ProductsA; i++)
		if (Form2->IsDel[i] == false) {
			AddLeft(i);
			IsLeft[-1][i]=true;
		}

}

// ---------------------------------------------------------------------------
void __fastcall TForm3::AddClickF(int num)
{
   int i;
if(PropNum==-1)
	i=-1;
	else
	i=PropNum;

	int k = Form6->ScrollBox1->VertScrollBar->Position;
	Form6->ScrollBox1->VertScrollBar->Position = 0;
	int k1 = Form6->ScrollBox2->VertScrollBar->Position;
	Form6->ScrollBox2->VertScrollBar->Position = 0;

	if(IsLeft[i][num]==true)
	{


		ProductsUse++;
		ProductsHave--;
		IsLeft[i][num] = false;
		IsRight[i][num] = true;
		PanelsHave[num]->Parent=Form6->ScrollBox2;
		for(int j=0;j<ProductsUse+ProductsHave;j++)
		if(IsLeft[i][j] && PanelsHave[j]->Top>PanelsHave[num]->Top)
			PanelsHave[j]->Top-=PanelHaveH;
		PanelsHave[num]->Top=(ProductsUse-1)*PanelHaveH;
	}
	else
	{
		ProductsUse--;
		ProductsHave++;
		IsLeft[i][num] = true;
		IsRight[i][num] = false;
		PanelsHave[num]->Parent=Form6->ScrollBox1;
		for(int j=0;j<ProductsUse+ProductsHave;j++)
		if(IsRight[i][j] && PanelsHave[j]->Top>PanelsHave[num]->Top)
			PanelsHave[j]->Top-=PanelHaveH;
		PanelsHave[num]->Top=(ProductsHave-1)*PanelHaveH;
	}

	Form6->ScrollBox1->VertScrollBar->Position = k;
    Form6->ScrollBox2->VertScrollBar->Position = k1;
}
void __fastcall TForm3::AddClick(TObject *Sender)
{
TButton *btn = dynamic_cast<TButton *>(Sender);
int num=btn->Tag;
AddClickF(num);
}
//------------------------------------------------------------------------------
void __fastcall TForm3::PropClick(TObject *Sender)
{
  TButton *btn = dynamic_cast<TButton *>(Sender);
  int num=btn->Tag;
  PropNum=num;
  	ProductsHave = 0;
	ProductsUse = 0;
	for (int i = 0; i < Form2->ProductsA; i++)
		PanelsHave[i]->Free();
	for (int i = 0; i < Form2->ProductsA; i++)
		if (Form2->IsDel[i] == false) {
			AddLeft(i);
		}
  for(int i=0;i<Form2->ProductsA;i++)
{
	if(IsRight[num][i])
	{
	   IsRight[num][i]==false;
	   IsLeft[num][i]=true;
	   AddClickF(i);
	}
	Form6->Show();
}
}
//------------------------------------------------------------------------------

