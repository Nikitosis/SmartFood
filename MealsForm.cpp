//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Products.h"
#include "MealsForm.h"
#include "Meals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
if(Form3->PropNum==99)
{
		Form3->MealsA++;
		int n=Form3->MealsA-1;
		int k;
		k=Form3->ScrollBox1->VertScrollBar->Position;  //����� �����������,����� �����. ��������
		Form3->ScrollBox1->VertScrollBar->Position=0;

		Form3->Panels[n]=new TPanel(Form3);
		Form3->Panels[n]->Parent=Form3->ScrollBox1;
		Form3->Panels[n]->Top=(Form3->MealsA-1-Form3->MealsDel)*Form3->PanelH;
		Form3->Panels[n]->Left=0;
		Form3->Panels[n]->Width=Form3->ScrollBox1->Width-4;
		Form3->Panels[n]->Height=Form3->PanelH;

		Form3->ScrollBox1->VertScrollBar->Position=k;


		Form3->Images[n]=new TImage(Form3);
		Form3->Images[n]->Parent=Form3->Panels[n];
		Form3->Images[n]->Left=150;
		Form3->Images[n]->Height=Form3->PanelH-1;
		Form3->Images[n]->Width=125;
		Form3->Images[n]->Stretch=true;
		Form3->Images[n]->Picture=Image1->Picture;


		Form3->Memos[n]=new TMemo(Form3);
		Form3->Memos[n]->Parent=Form3->Panels[n];
		Form3->Memos[n]->Left=277;
		Form3->Memos[n]->Height=Form3->PanelH-1;
		Form3->Memos[n]->Width=273;
		Form3->Memos[n]->ReadOnly=true;
		Form3->Memos[n]->ScrollBars=ssBoth;
		Form3->Memos[n]->Lines->Text=Form6->Memo1->Lines->Text;

		Form3->Labeles[n*5]=new TLabel(Form3);
		Form3->Labeles[n*5]->Parent=Form3->Panels[n];
		Form3->Labeles[n*5]->Top=40;
		Form3->Labeles[n*5]->Left=10;
		Form3->Labeles[n*5]->WordWrap=true;
		Form3->Labeles[n*5]->AutoSize=false;
		Form3->Labeles[n*5]->Height=50;
		Form3->Labeles[n*5]->Width=130;
		Form3->Labeles[n*5]->Font->Size=14;
		Form3->Labeles[n*5]->Caption=Form6->Edit1->Text;

		Form3->Labeles[n*5+1]=new TLabel(Form3);
		Form3->Labeles[n*5+1]->Parent=Form3->Panels[n];
		Form3->Labeles[n*5+1]->Top=40;
		Form3->Labeles[n*5+1]->Left=560;
		Form3->Labeles[n*5+1]->WordWrap=true;
		Form3->Labeles[n*5+1]->AutoSize=false;
		Form3->Labeles[n*5+1]->Height=20;
		Form3->Labeles[n*5+1]->Width=70;
		Form3->Labeles[n*5+1]->Font->Size=10;
		Form3->Labeles[n*5+1]->Caption=Label5->Caption;

		Form3->Labeles[n*5+2]=new TLabel(Form3);
		Form3->Labeles[n*5+2]->Parent=Form3->Panels[n];
		Form3->Labeles[n*5+2]->Top=40;
		Form3->Labeles[n*5+2]->Left=683;
		Form3->Labeles[n*5+2]->WordWrap=true;
		Form3->Labeles[n*5+2]->AutoSize=false;
		Form3->Labeles[n*5+2]->Height=20;
		Form3->Labeles[n*5+2]->Width=70;
		Form3->Labeles[n*5+2]->Font->Size=10;
		Form3->Labeles[n*5+2]->Caption=Label6->Caption;

		Form3->Labeles[n*5+3]=new TLabel(Form3);
		Form3->Labeles[n*5+3]->Parent=Form3->Panels[n];
		Form3->Labeles[n*5+3]->Top=40;
		Form3->Labeles[n*5+3]->Left=806;
		Form3->Labeles[n*5+3]->WordWrap=true;
		Form3->Labeles[n*5+3]->AutoSize=false;
		Form3->Labeles[n*5+3]->Height=20;
		Form3->Labeles[n*5+3]->Width=70;
		Form3->Labeles[n*5+3]->Font->Size=10;
		Form3->Labeles[n*5+3]->Caption=Label7->Caption;

		Form3->Labeles[n*5+4]=new TLabel(Form3);
		Form3->Labeles[n*5+4]->Parent=Form3->Panels[n];
		Form3->Labeles[n*5+4]->Top=40;
		Form3->Labeles[n*5+4]->Left=929;
		Form3->Labeles[n*5+4]->WordWrap=true;
		Form3->Labeles[n*5+4]->AutoSize=false;
		Form3->Labeles[n*5+4]->Height=20;
		Form3->Labeles[n*5+4]->Width=70;
		Form3->Labeles[n*5+4]->Font->Size=10;
		Form3->Labeles[n*5+4]->Caption=Label8->Caption;

		Form3->Buttons[n]=new TButton(Form3);
		Form3->Buttons[n]->Parent=Form3->Panels[n];
		Form3->Buttons[n]->Left=1043;
		Form3->Buttons[n]->Height=Form3->PanelH-1;
		Form3->Buttons[n]->Width=110;
		Form3->Buttons[n]->Tag=n;
		Form3->Buttons[n]->OnClick=Form3->PropClick;


		TImage *line=new TImage(Form3);               //������ �����
		line->Parent=Form3->Panels[n];
		line->Left=150;
		line->Width=2;
		line->Height=Form3->PanelH-1;
		line->Picture->Bitmap->Width=2;
		line->Picture->Bitmap->Height=Form3->PanelH-1;
		line->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line1=new TImage(Form3);
		line1->Parent=Form3->Panels[n];
		line1->Left=275;
		line1->Width=2;
		line1->Height=Form3->PanelH-1;
		line1->Picture->Bitmap->Width=2;
		line1->Picture->Bitmap->Height=Form3->PanelH-1;
		line1->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line1->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line2=new TImage(Form3);
		line2->Parent=Form3->Panels[n];
		line2->Left=427;
		line2->Width=2;
		line2->Height=Form3->PanelH-1;
		line2->Picture->Bitmap->Width=2;
		line2->Picture->Bitmap->Height=Form3->PanelH-1;
		line2->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line2->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line3=new TImage(Form3);
		line3->Parent=Form3->Panels[n];
		line3->Left=550;
		line3->Width=2;
		line3->Height=Form3->PanelH-1;
		line3->Picture->Bitmap->Width=2;
		line3->Picture->Bitmap->Height=Form3->PanelH-1;
		line3->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line3->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line4=new TImage(Form3);
		line4->Parent=Form3->Panels[n];
		line4->Left=673;
		line4->Width=2;
		line4->Height=Form3->PanelH-1;
		line4->Picture->Bitmap->Width=2;
		line4->Picture->Bitmap->Height=Form3->PanelH-1;
		line4->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line4->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line5=new TImage(Form3);
		line5->Parent=Form3->Panels[n];
		line5->Left=796;
		line5->Width=2;
		line5->Height=Form3->PanelH-1;
		line5->Picture->Bitmap->Width=2;
		line5->Picture->Bitmap->Height=Form3->PanelH-1;
		line5->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line5->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line6=new TImage(Form3);
		line6->Parent=Form3->Panels[n];
		line6->Left=919;
		line6->Width=2;
		line6->Height=Form3->PanelH-1;
		line6->Picture->Bitmap->Width=2;
		line6->Picture->Bitmap->Height=Form3->PanelH-1;
		line6->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line6->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		TImage *line7=new TImage(Form3);
		line7->Parent=Form3->Panels[n];
		line7->Left=1042;
		line7->Width=2;
		line7->Height=Form3->PanelH-1;
		line7->Picture->Bitmap->Width=2;
		line7->Picture->Bitmap->Height=Form3->PanelH-1;
		line7->Picture->Bitmap->Canvas->Brush->Color=clBlack;
		line7->Picture->Bitmap->Canvas->FillRect(Rect(0,0,2,100));

		for(int i=0;i<Form2->ProductsA;i++)
		{
			Form3->IsLeft[n][i]=Form3->IsLeft[99][i];
			Form3->IsRight[n][i]=Form3->IsRight[99][i];
		}

		for(int i=0;i<Form2->ProductsA;i++)
			Form3->Weights[n][i]=Form3->EditsHave[i]->Text;
	}
	else
	{
		int n=Form3->PropNum;
		Form3->Memos[n]->Text=Memo1->Text;
		Form3->Images[n]->Picture=Image1->Picture;
		Form3->Labeles[n*5]->Caption=Edit1->Text;
		Form3->Labeles[n*5+1]->Caption=Label5->Caption;
		Form3->Labeles[n*5+2]->Caption=Label6->Caption;
		Form3->Labeles[n*5+3]->Caption=Label7->Caption;
		Form3->Labeles[n*5+4]->Caption=Label8->Caption;
		for(int i=0;i<Form2->ProductsA;i++)
			Form3->Weights[n][i]=Form3->EditsHave[i]->Text;
    }


	Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
if(Form3->PropNum!=-1)
{
	int num=Form3->PropNum;
	for(int i=0;i<Form2->ProductsA;i++)
	{
	  Form3->IsLeft[num][i]=Form3->LeftWas[i];
	  Form3->IsRight[num][i]=Form3->RightWas[i];
	}
}
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
if (OpenPictureDialog1->Execute())
	{
		 Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
	}
}
//---------------------------------------------------------------------------






void __fastcall TForm6::Button4Click(TObject *Sender)      //������� meals
{
	Form3->Panels[Form3->PropNum]->Free();
	for(int i=0;i<Form3->MealsA;i++)
	  if(Form3->IsDelMeal[i]==false && Form3->Panels[i]->Top>Form3->Panels[Form3->PropNum]->Top)
	  	Form3->Panels[i]->Top-=Form3->PanelH;

	for(int i=0;i<Form2->ProductsA;i++)
	{
		Form3->IsLeft[Form3->PropNum][i]=true;
		Form3->IsRight[Form3->PropNum][i]=false;
	}
	Form3->MealsDel++;
	Form3->IsDelMeal[Form3->PropNum]=true;
	Form6->Close();
}
//---------------------------------------------------------------------------
