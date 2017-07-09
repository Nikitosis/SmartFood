// ---------------------------------------------------------------------------

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
#include "RecommendMeals.h"
#include "Instruction.h"
#include "About.h"
#include <limits>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	// Form1->Hide();
	Form3->Hide();
	Form4->Hide();
	Form5->Hide();
	Form6->Hide();
	Form8->Hide();
	Form2->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Form2->Hide();
	Form4->Hide();
	Form5->Hide();
	Form6->Hide();
	Form8->Hide();
	Form3->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	Form3->Hide();
	Form4->Hide();
	Form5->Hide();
	Form6->Hide();
	Form8->Hide();
	Form2->Hide();
	Form4->Show();

	Form4->Edit1->Text = "";
	Form4->Edit2->Text = "";
	Form4->Edit3->Text = "";
	Form4->ComboBox1->ItemIndex = -1;
	Form4->ComboBox1->Text = "���";
	Form4->ComboBox2->ItemIndex = -1;
	Form4->ComboBox2->Text = "������� ����������";
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Save1Click(TObject *Sender) {

	ios_base::sync_with_stdio(0);
	SaveDialog1->Filter = "Products|*.prd";
	SaveDialog1->DefaultExt = "prd";
	if (SaveDialog1->Execute())
	{
		ofstream fout;
		setlocale(LC_CTYPE, ".1251");
		fout.open(SaveDialog1->FileName.c_str());

		Graphics::TBitmap* gBitmap = new Graphics::TBitmap;
		Graphics::TBitmap* gBitmap2 = new Graphics::TBitmap;
		int imgh = 100; // ������ ����������� ��������
		int imgw = 100;

		fout << Form3->Meal.size() << endl;
		fout << Form2->Product.size()<<endl;
		//////////////////////////Meals
		for (int i = 0; i < Form3->Meal.size(); i++)
			 {
				AnsiString s;

				s = Form3->Meal[i].Name->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form3->Meal[i].Protein->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form3->Meal[i].Fat->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form3->Meal[i].Carbon->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form3->Meal[i].Calories->Caption.c_str();
				fout << s.c_str() << endl;

				fout << Form3->Meal[i].Memo->Lines->Count << endl;
				s = Form3->Meal[i].Memo->Lines->Text.c_str();
				fout << s.c_str() << endl;

				gBitmap2->Assign(Form3->Meal[i].Image->Picture->Graphic);    // ��������� ��������
				gBitmap->Width = imgh;
				gBitmap->Height = imgw;
				gBitmap->Canvas->StretchDraw(Rect(0, 0, 100, 100), gBitmap2);
				fout << imgw << " " << imgh << endl;
				for (int x = 0; x < imgw; x++)
					for (int y = 0; y < imgh; y++) {
						s = ColorToString(gBitmap->Canvas->Pixels[x][y]);
						fout << s.c_str() << " ";
					}
				fout<<endl;
			}

		fout << endl;
		//////////////////////////////////////////Products

		for (int i = 0; i < Form2->Product.size(); i++)
			{
				AnsiString s;

				s = Form2->Product[i].Name->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form2->Product[i].Protein->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form2->Product[i].Fat->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form2->Product[i].Carbon->Caption.c_str();
				fout << s.c_str() << endl;

				s = Form2->Product[i].Calories->Caption.c_str();
				fout << s.c_str() << endl;

				gBitmap2->Assign(Form2->Product[i].Image->Picture->Graphic); 		// ��������� ��������

				gBitmap->Width = imgh;
				gBitmap->Height = imgw;
				gBitmap->Canvas->StretchDraw(Rect(0, 0, 100, 100), gBitmap2);
				fout << imgw << " " << imgh << endl;
				for (int x = 0; x < imgw; x++)
					for (int y = 0; y < imgh; y++) {
						s = ColorToString(gBitmap->Canvas->Pixels[x][y]);
						fout << s.c_str() << " ";
					}
				fout<<endl;
			}
		gBitmap2->Free(); // ����������� ������ ��������
		gBitmap->Free();

		for (int i = 0; i < Form2->Product.size(); i++)
		{
				AnsiString s;
				s = Form2->Product[i].MassProtein.c_str();
				fout << s.c_str() << endl;

				s = Form2->Product[i].MassFat.c_str();
				fout << s.c_str() << endl;

				s = Form2->Product[i].MassCarbon.c_str();
				fout << s.c_str() << endl;
		}

		for (int i = 0; i < Form3->Meal.size(); i++)   // IsLeft
			for (int j = 0; j < Form2->Product.size(); j++) {
				fout << Form3->Meal[i].IsLeft[j] << endl;
			}

		for (int i = 0; i < Form3->Meal.size(); i++)   // IsRight
			for (int j = 0; j < Form2->Product.size(); j++) {
				fout << Form3->Meal[i].IsRight[j] << endl;
			}

		for (int i = 0; i < Form3->Meal.size(); i++)  //Weight
			for (int j = 0; j < Form2->Product.size(); j++) {
				AnsiString s;
				s = Form3->Meal[i].Weight[j].c_str();
				fout << s.c_str() << " ";
			}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Load1Click(TObject *Sender) {
	ios_base::sync_with_stdio(0);
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	OpenDialog1->Filter = "Products|*.prd";
	OpenDialog1->DefaultExt = "prd";
	if (OpenDialog1->Execute()) {

		ifstream fin;
		setlocale(LC_CTYPE, ".1251");
		fin.open(OpenDialog1->FileName.c_str());

		for (int i = 0; i < Form2->Product.size(); i++) //  ������� ������
			Form2->Product[i].Panel->Free();
		for(int i=0;i<Form3->Meal.size();i++)
			Form3->Meal[i].Panel->Free();

		Form2->Product.clear();
		Form3->Meal.clear();

		Graphics::TBitmap* gBitmap = new Graphics::TBitmap;
		gBitmap->Transparent = false;

		int MealNum,ProdNum;
		fin >> MealNum;
		fin>>ProdNum;

		string s;
		//////////////////////Meals
		for (int i = 0; i < MealNum; i++)  //������� ����� Meal � ����������� ��� ��� �����������
		{
			fin.ignore(numeric_limits<streamsize>::max(), '\n');  //������� �����
			Form3->CreateNewMeal();
			Form3->PropNum=i;
			Form6->Button2Click(this);
			getline(fin, s);
			Form3->Meal[i].Name->Caption = s.c_str();

			getline(fin, s);
			Form3->Meal[i].Protein->Caption = s.c_str();

			getline(fin, s);
			Form3->Meal[i].Fat->Caption = s.c_str();

			getline(fin, s);
			Form3->Meal[i].Carbon->Caption = s.c_str();

			getline(fin, s);
			Form3->Meal[i].Calories->Caption = s.c_str();

			int linesA;
			fin >> linesA;
			getline(fin, s);
			Form3->Meal[i].Memo->Lines->Clear();
			for (int j = 0; j < linesA; j++) {
				getline(fin, s);
				Form3->Meal[i].Memo->Lines->Add(s.c_str());
			}

			int w, h;
			fin >> w >> h;
			gBitmap->Width = w;
			gBitmap->Height = h;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');  //������� �����
			for (int x = 0; x < w; x++)
				for (int y = 0; y < h; y++) {
					fin>>s;
					gBitmap->Canvas->Pixels[x][y] = StringToColor(s.c_str());
				}
			Form3->Meal[i].Image->Picture->Graphic = gBitmap;
		}

		//if(MealNum==0 || ProdNum==0)
			fin.ignore(numeric_limits<streamsize>::max(), '\n');  //������� �����

		////////////////Products
		Form5->Button4->Visible = false;
		for (int i = 0; i < ProdNum; i++)  //������� ������� � ����������� ��� �����������
		{
			fin.ignore(numeric_limits<streamsize>::max(), '\n');  //������� �����
			Form2->Button1Click(this);
			Form5->Button2Click(this);
			getline(fin, s);
			Form2->Product[i].Name->Caption = s.c_str();

			getline(fin, s);
			Form2->Product[i].Protein->Caption = s.c_str();

			getline(fin, s);
			Form2->Product[i].Fat->Caption = s.c_str();

			getline(fin, s);
			Form2->Product[i].Carbon->Caption = s.c_str();

			getline(fin, s);
			Form2->Product[i].Calories->Caption = s.c_str();

			int w, h;
			fin >> w >> h;
			gBitmap->Width = w;
			gBitmap->Height = h;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');  //������� �����
			for (int x = 0; x < w; x++)
				for (int y = 0; y < h; y++) {
					fin>>s;
					gBitmap->Canvas->Pixels[x][y] = StringToColor(s.c_str());
				}
			Form2->Product[i].Image->Picture->Graphic = gBitmap;
		}
		gBitmap->Free();

        getline(fin,s);
		for (int i = 0; i < ProdNum; i++) // ����� �/�/� ��� ������� products
		{
			getline(fin, s);
			Form2->Product[i].MassProtein = s.c_str();

			getline(fin, s);
			Form2->Product[i].MassFat = s.c_str();

			getline(fin, s);
			Form2->Product[i].MassCarbon = s.c_str();
		}

		for(int i=0;i<MealNum;i++)      // IsLeft
			for(int j=0;j<ProdNum;j++)
			{
				fin>>Form3->Meal[i].IsLeft[j];
				bool b=Form3->Meal[i].IsLeft[j];
				int k=12;
			}

		for(int i=0;i<MealNum;i++)      // IsRight
			for(int j=0;j<ProdNum;j++)
			{
				fin>>Form3->Meal[i].IsRight[j];
				bool b=Form3->Meal[i].IsRight[j];
				int k=12;
			}

		for(int i=0;i<MealNum;i++)      // Weight
			for(int j=0;j<ProdNum;j++)
			{
				fin>>s;
				Form3->Meal[i].Weight[j]=s.c_str();
			}

		for(int i=0;i<MealNum;i++)
			Form3->RecountCalFromProd(i);
	}

	Form3->Hide();
	Form2->Hide();
	Form8->Hide();
	Form4->Hide();
	Form3->Hide();
	Form1->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1MouseEnter(TObject *Sender) {
	AnsiString s = ExtractFilePath(Application->ExeName);
	Button1->Picture->LoadFromFile(s + "/MenuButtons/MouseEnter.png");
	Button2->Picture->LoadFromFile(s + "/MenuButtons/Button.png");
	Button3->Picture->LoadFromFile(s + "/MenuButtons/Button.png");

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2MouseEnter(TObject *Sender) {
	AnsiString s = ExtractFilePath(Application->ExeName);
	Button1->Picture->LoadFromFile(s + "/MenuButtons/Button.png");
	Button2->Picture->LoadFromFile(s + "/MenuButtons/MouseEnter.png");
	Button3->Picture->LoadFromFile(s + "/MenuButtons/Button.png");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3MouseEnter(TObject *Sender) {
	AnsiString s = ExtractFilePath(Application->ExeName);
	Button1->Picture->LoadFromFile(s + "/MenuButtons/Button.png");
	Button2->Picture->LoadFromFile(s + "/MenuButtons/Button.png");
	Button3->Picture->LoadFromFile(s + "/MenuButtons/MouseEnter.png");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	setlocale(LC_ALL, "rus");
	AnsiString s = ExtractFilePath(Application->ExeName);
	s += "/Fonts/segoepr.ttf";
	AddFontResource(s.c_str());

	IsKeyboard = false;

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender) {
	IsKeyboard = true;
	N2->Checked = true;
	N3->Checked = false;

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender) {
	IsKeyboard = false;
	N2->Checked = false;
	N3->Checked = true;
	Form11->Panel4->Visible = false; // ��������� �����
	Form6->Panel4->Visible = false;
	Form5->Panel4->Visible = false;
	Form4->Panel4->Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender) {
	Form11->Panel4->Visible = false; // ��������� �����
	Form6->Panel4->Visible = false;
	Form5->Panel4->Visible = false;
	Form4->Panel4->Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender) {
	Form9->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender) {
	Form10->Show();
}
// ---------------------------------------------------------------------------
