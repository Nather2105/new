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
    Canvas->Pen  ->Color = clRed;     // змінюємо колір обводки на червоний
    Canvas->Brush->Color = clRed;     // змінюємо колір заливки на червоний
    Canvas->Rectangle( 0, 0, 1100, 550); // малюємо червоний прямокутник(можна було два функціями заради економії)

     // 1100; довжина
     //  550; висота

    Canvas->Pen  ->Color = clWhite; // змінюємо колір обводки на білий
    Canvas->Brush->Color = clWhite; // змінюємо колір заливки на білий
    Canvas->Rectangle( 275, 550, 825, 0); // малюємо білий квадрат

    TPoint Pt[24]; // створюємо масив для Функції полігон

    int dx[12] = {0, 40, 80, 60, 120, 130, 200, 180, 210, 100, 120,  6};
    int dy[12] = {50, 130, 110, 240, 180, 210, 190, 260, 280, 370, 425, 400};
    for(int i = 0; i < 12; i++)
    {
        Pt[i] = Point(550 + dx[i], dy[i]);     // для дзеркальності
        Pt[23-i] = Point(550 - dx[i], dy[i]);
    }
    Canvas->Pen->Width=12;   // ширина пензля = 12
    Canvas->Brush->Color = clRed; // змінюємо колір заливки на червоний
    Canvas->Polygon(Pt, 23);      // з'єднуємо точки

    TPoint Pt1[2];   // даний масив використовується для зоображення палечки
    int dx1[2] = {6, 10};
    int dy1[2] = {384, 500};
    for(int i = 0; i < 2; i++)
    {
        Pt1[i] = Point(550 + dx1[i], dy1[i]);       // для дзеркальності
        Pt1[3-i] = Point(550 - dx1[i], dy1[i]);
    }
    Canvas->Pen  ->Color = clRed; // змінюємо колір обводки на червоний
    Canvas->Pen->Width=3;         // ширина пензля = 3
    Canvas->Brush->Color = clRed;  // змінюємо колір заливки на червоний
    Canvas->Polygon(Pt1, 3);

    Canvas->Pen->Width=20;        // ширина пензля = 20
    Canvas->Pen->Color = clWhite; // змінюємо колір обводки на білий
    Canvas->Brush->Color = clWhite; // змінюємо колір заливки на білий

    TPoint Pt2[3];   // для згладки  місця між листком та стовбуром
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
