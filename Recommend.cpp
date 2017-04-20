//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

#include "Products.h"
#include "Main.h"
#include "Meals.h"
#include "Recommend.h"
#include "RecommendDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
if(Edit1->Text=="" || Edit2->Text=="" || Edit3->Text=="")
{
	ShowMessage("��������� ���� �����,���� � ��������");
}
else
	if(ComboBox1->ItemIndex<0 || ComboBox2->ItemIndex<0)
		ShowMessage("�������� ��� ��� � ������� ����������");
		else
		{
			double weight=StrToInt(Edit2->Text);
			double height=StrToInt(Edit1->Text);
			double age=StrToInt(Edit3->Text);
			if(ComboBox1->ItemIndex==0)
				BMR=88.36+(13.4*weight)+(4.8*height)-(5.7*age);
				else
				BMR=447.6 + (9.2*weight) + (3.1*height) - (4.3*age);
			if(ComboBox2->ItemIndex==1)
			  BMR*=1.2;
			if(ComboBox2->ItemIndex==2)
			  BMR*=1.375;
			if(ComboBox2->ItemIndex==3)
			  BMR*=1.55;
			if(ComboBox2->ItemIndex==4)
			  BMR*=1.725;
			if(ComboBox2->ItemIndex==5)
			  BMR*=1.9;
			BMR=ceil(BMR);
			Form8->Label1->Caption="���� ������������� ���������� ���� � ����: " +FloatToStr(BMR);
			Form8->BMR=BMR;
			Form8->ShowModal();
		}

}
//---------------------------------------------------------------------------

