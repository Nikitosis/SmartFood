//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include <iostream.h>
#include <string>
#include <windows.h>

#include "Main.h"
#include "Products.h"
#include "Meals.h"
#include "Recommend.h"
#include "MealsForm.h"
#include "ProdForm.h"
#include "RecommendDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
setlocale(LC_ALL, "Russian");
SetConsoleCP(1251);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//Form1->Hide();
Form3->Hide();
Form4->Hide();
Form5->Hide();
Form6->Hide();
Form8->Hide();
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form2->Hide();
Form4->Hide();
Form5->Hide();
Form6->Hide();
Form8->Hide();
Form3->Show();

Form3->Panel1->Visible=false;
Form3->Panel2->Visible=false;
Form3->Panel3->Visible=false;
Form3->Label8->Visible=false;
Form3->Label9->Visible=false;
Form3->Label10->Visible=false;

Form3->IsRecommend=false;
for(int i=0;i<Form3->MealsA;i++)
	if(Form3->IsDelMeal[i]==false)
		Form3->RecomPanel[i]->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form3->Hide();
Form4->Hide();
Form5->Hide();
Form6->Hide();
Form8->Hide();
Form2->Hide();
Form4->Show();

Form4->Edit1->Text="";
Form4->Edit2->Text="";
Form4->Edit3->Text="";
Form4->ComboBox1->ItemIndex=-1;
Form4->ComboBox1->Text="���";
Form4->ComboBox2->ItemIndex=-1;
Form4->ComboBox2->Text="������� ����������";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{
	  if(SaveDialog1->Execute())
	  {
		   ofstream fout(SaveDialog1->FileName.c_str());

		   Graphics::TBitmap*   gBitmap = new Graphics::TBitmap;
		   Graphics::TBitmap*   gBitmap2 = new Graphics::TBitmap;
		   int imgh=100; //������ ����������� ��������
		   int imgw=100;

		   fout<<Form3->MealsA-Form3->MealsDel<<endl;
		   for(int i=0;i<Form3->MealsA;i++)
		   if(Form3->IsDelMeal[i]==false)
		   {
			 AnsiString s;

			 s=Form3->Labeles[i*5]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+1]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+2]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+3]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 s=Form3->Labeles[i*5+4]->Caption.c_str();
			 fout<<s.c_str()<<endl;

			 fout<<Form3->Memos[i]->Lines->Count<<endl;
			 s=Form3->Memos[i]->Lines->Text.c_str();
			 fout<<s.c_str()<<endl;

			  gBitmap2->Assign(Form3->Images[i]->Picture->Graphic);  	//��������� ��������
				   gBitmap->Width=imgh;
				   gBitmap->Height=imgw;
				   gBitmap->Canvas->StretchDraw(Rect(0,0,100,100),gBitmap2);
				   fout<<imgw<<" "<<imgh<<endl;
				   for(int x=0;x<imgw;x++)
					for(int y=0;y<imgh;y++)
						{
							s=ColorToString(gBitmap->Canvas->Pixels[x][y]);
							fout<<s.c_str()<<endl;
						}
		   }

		   for(int i=0;i<99;i++)
		   for(int j=0;j<99;j++)
		   fout<<Form3->IsLeft[i][j]<<" ";
		   fout<<endl;

		   for(int i=0;i<99;i++)
		   for(int j=0;j<99;j++)
		   fout<<Form3->IsRight[i][j]<<" ";
		   fout<<endl;

		   for(int i=0;i<99;i++)
		   for(int j=0;j<99;j++)
		   {
			 AnsiString s;
			 s=Form3->Weights[i][j].c_str();
		     fout<<s.c_str()<<" ";
		   }
		   fout<<endl;
		   //////////////////////////////////////////

		   fout<<Form2->ProductsA-Form2->ProductsDel<<endl;

		   for(int i=0;i<Form2->ProductsA;i++)
			 if(Form2->IsDel[i]==false)     //�������� �� ��,��� �� �� ������� ��� ������(����� ������� �� ����������� ����� � ��������)
			   {
				   AnsiString s;

				   s=Form2->Labeles[i*5]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+1]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+2]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+3]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   s=Form2->Labeles[i*5+4]->Caption.c_str();
				   fout<<s.c_str()<<endl;

				   gBitmap2->Assign(Form2->Images[i]->Picture->Graphic);  	//��������� ��������
				   gBitmap->Width=imgh;
				   gBitmap->Height=imgw;
				   gBitmap->Canvas->StretchDraw(Rect(0,0,100,100),gBitmap2);
				   fout<<imgw<<" "<<imgh<<endl;
				   for(int x=0;x<imgw;x++)
					for(int y=0;y<imgh;y++)
						{
							s=ColorToString(gBitmap->Canvas->Pixels[x][y]);
							fout<<s.c_str()<<endl;
						}
			   }
	  	  gBitmap2->Free(); //����������� ������ ��������
		  gBitmap->Free();

		  for(int i=0;i<Form2->ProductsA;i++)
		 {
			 if(Form2->IsDel[i]==false)
			 {
				 AnsiString s;
				 s=Form5->Masses[i*3].c_str();
				 fout<<s.c_str()<<endl;

				 s=Form5->Masses[i*3+1].c_str();
				 fout<<s.c_str()<<endl;

				 s=Form5->Masses[i*3+2].c_str();
				 fout<<s.c_str()<<endl;
			 }
		 }
	  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Load1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
	ifstream fin(OpenDialog1->FileName.c_str());

		for(int i=0;i<Form2->ProductsA;i++)                      //��������� Products
		if(Form2->IsDel[i]==false)
		 Form2->Panels[i]->Free();

        for(int i=0;i<Form3->MealsA;i++)
		if(Form3->IsDelMeal[i]==false)
		 Form3->Panels[i]->Free();

		 memset(Form2->IsDel,false,100*sizeof(bool));
		 memset(Form3->IsDelMeal,false,100*sizeof(bool));
		 Graphics::TBitmap*   gBitmap = new Graphics::TBitmap;
		 gBitmap->Transparent=false;

		int n;
		fin>>n;
		Form3->PropNum=99;
		Form2->ProductsA=0;
		Form3->MealsA=0;
		Form2->ProductsDel=0;
		Form3->MealsDel=0;

		string s;
	    getline(fin,s);
		for(int i=0;i<n;i++) //Meals
		{
		  Form6->Button2Click(this);
		  getline(fin,s);
		  Form3->Labeles[i*5]->Caption=s.c_str();

          getline(fin,s);
		  Form3->Labeles[i*5+1]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Labeles[i*5+2]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Labeles[i*5+3]->Caption=s.c_str();

		  getline(fin,s);
		  Form3->Labeles[i*5+4]->Caption=s.c_str();


		  int linesA;
		  fin>>linesA;
		  getline(fin,s);
		  Form3->Memos[i]->Lines->Clear();
		  for(int j=0;j<linesA;j++)
		  {
			  getline(fin,s);
			  Form3->Memos[i]->Lines->Add(s.c_str());
		  }

		  int w,h;
		  fin>>w>>h;
		  gBitmap->Width=w;
		  gBitmap->Height=h;
		  getline(fin,s);
		  for(int x=0;x<w;x++)
			for(int y=0;y<h;y++)
				{
					getline(fin,s);
					gBitmap->Canvas->Pixels[x][y]=StringToColor(s.c_str());
				}
		  Form3->Images[i]->Picture->Graphic=gBitmap;
		}

					bool b;
	  for(int i=0;i<99;i++)
		for(int j=0;j<99;j++)
		{
			fin>>b;
		 Form3->IsLeft[i][j]=b;
		}

	  for(int i=0;i<99;i++)
		for(int j=0;j<99;j++)
		{
			fin>>b;
		  Form3->IsRight[i][j]=b;
		}

      for(int i=0;i<99;i++)
		for(int j=0;j<99;j++)
		{
			fin>>s;
            Form3->Weights[i][j]=s.c_str();
		}
		/////////////////////////////////////////////////////////     ��������� Products
	    n;
		fin>>n;
		Form5->Button4->Visible=false;
		getline(fin,s);
		for(int i=0;i<n;i++)
		{
		  Form5->Button2Click(this);
		  getline(fin,s);
		  Form2->Labeles[i*5]->Caption=s.c_str();

          getline(fin,s);
		  Form2->Labeles[i*5+1]->Caption=s.c_str();

		  getline(fin,s);
		  Form2->Labeles[i*5+2]->Caption=s.c_str();

		  getline(fin,s);
		  Form2->Labeles[i*5+3]->Caption=s.c_str();

		  getline(fin,s);
		  Form2->Labeles[i*5+4]->Caption=s.c_str();

		  int w,h;
		  fin>>w>>h;
		  gBitmap->Width=w;
		  gBitmap->Height=h;
		  getline(fin,s);
		  for(int x=0;x<w;x++)
			for(int y=0;y<h;y++)
				{
					getline(fin,s);
					gBitmap->Canvas->Pixels[x][y]=StringToColor(s.c_str());
					//gBitmap->Canvas->Pixels[x][y]=clRed;
					//Form2->Label1->Font->Color=StringToColor("0x000605FB");
				}
		  Form2->Images[i]->Picture->Graphic=gBitmap;
		  Form2->Image1->Picture->Graphic=gBitmap;
		}
	   gBitmap->Free();

	   for(int i=0;i<Form2->ProductsA;i++)    //����� �/�/� ��� ������� products
	   {
			getline(fin,s);
		  Form5->Masses[i*3]=s.c_str();

		  	getline(fin,s);
		  Form5->Masses[i*3+1]=s.c_str();

		  	getline(fin,s);
		  Form5->Masses[i*3+2]=s.c_str();

	   }
	}
	Form3->Close();
	Form2->Close();
	Form8->Close();
	Form4->Close();
	Form3->Hide();
	//Form2->Hide();
	Form1->Show();
}
//---------------------------------------------------------------------------







