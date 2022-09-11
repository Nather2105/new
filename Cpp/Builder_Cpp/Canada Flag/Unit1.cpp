//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Canvas->Pen  ->Color = clRed;     // ������� ���� ������� �� ��������
    Canvas->Brush->Color = clRed;     // ������� ���� ������� �� ��������
    Canvas->Rectangle( 0, 0, 1100, 550); // ������� �������� �����������(����� ���� ��� ��������� ������ �����쳿)

     // 1100; �������
     //  550; ������

    Canvas->Pen  ->Color = clWhite; // ������� ���� ������� �� ����
    Canvas->Brush->Color = clWhite; // ������� ���� ������� �� ����
    Canvas->Rectangle( 275, 550, 825, 0); // ������� ���� �������

    TPoint Pt[24]; // ��������� ����� ��� ������� ������

    int dx[12] = {0, 40, 80, 60, 120, 130, 200, 180, 210, 100, 120,  6};
    int dy[12] = {50, 130, 110, 240, 180, 210, 190, 260, 280, 370, 425, 400};
    for(int i = 0; i < 12; i++)
    {
        Pt[i] = Point(550 + dx[i], dy[i]);     // ��� ������������
        Pt[23-i] = Point(550 - dx[i], dy[i]);
    }
    Canvas->Pen->Width=12;   // ������ ������ = 12
    Canvas->Brush->Color = clRed; // ������� ���� ������� �� ��������
    Canvas->Polygon(Pt, 23);      // �'������ �����

    TPoint Pt1[2];   // ����� ����� ��������������� ��� ����������� �������
    int dx1[2] = {6, 10};
    int dy1[2] = {384, 500};
    for(int i = 0; i < 2; i++)
    {
        Pt1[i] = Point(550 + dx1[i], dy1[i]);       // ��� ������������
        Pt1[3-i] = Point(550 - dx1[i], dy1[i]);
    }
    Canvas->Pen  ->Color = clRed; // ������� ���� ������� �� ��������
    Canvas->Pen->Width=3;         // ������ ������ = 3
    Canvas->Brush->Color = clRed;  // ������� ���� ������� �� ��������
    Canvas->Polygon(Pt1, 3);

    Canvas->Pen->Width=20;        // ������ ������ = 20
    Canvas->Pen->Color = clWhite; // ������� ���� ������� �� ����
    Canvas->Brush->Color = clWhite; // ������� ���� ������� �� ����

    TPoint Pt2[3];   // ��� �������  ���� �� ������� �� ���������
    Pt2[0]= Point(430,425);
    Pt2[1]= Point(534,398);
    Pt2[2]= Point(520,510);
    Canvas->Polygon(Pt2, 2);


    TPoint Pt3[3];
    Pt3[0]= Point(670, 425);
    Pt3[1]= Point(566, 398);
    Pt3[2]= Point(580, 510);
    Canvas->Polygon(Pt3, 2);

}
//---------------------------------------------------------------------------
