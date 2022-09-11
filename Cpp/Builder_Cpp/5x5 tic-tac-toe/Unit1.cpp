//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
int fl = 1; // показник ходу Х=1 О=0
int count = 0; // рахунок ходів
int mas[5][5] = { {-1, -1, -1, -1, -1,},{-1, -1, -1, -1, -1,},   //масив поля
{-1, -1, -1, -1, -1,}, {-1, -1, -1, -1, -1,}, {-1, -1, -1, -1, -1,} };  //пусто=-1 Х=1 О=0
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Button1->Visible=False;        //блокуєм видимість кнопок
Button2->Visible=False;
 Button3->Visible=False;
 Button4->Visible=False;
 Button5->Visible=False;
 Button6->Visible=False;
 Button7->Visible=False;
 Button8->Visible=False;
 Button9->Visible=False;
 Button10->Visible=False;
 Button11->Visible=False;
 Button12->Visible=False;
 Button13->Visible=False;
 Button14->Visible=False;
 Button15->Visible=False;
 Button16->Visible=False;
 Button17->Visible=False;
 Button18->Visible=False;
 Button19->Visible=False;
 Button20->Visible=False;
 Button21->Visible=False;
 Button22->Visible=False;
 Button23->Visible=False;
 Button24->Visible=False;
 Button25->Visible=False;
 Memo1->Visible=False;           //блокуєм мемо1
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StartClick(TObject *Sender)
{
 Start->Visible=False;     //блокуєм видимість кнопки початку
 Form1->Canvas->Pen->Width=20;    //ширина обводки 20
 Form1->Canvas->Brush->Color = clWhite; //колір заливки білий
 Form1->Canvas->Pen->Color = clBlack;   //колір обводки чорний
 Start1(105,105);  //малюємо вертикальні полоски для таблиці
 Start1(225,105);
 Start1(345,105);
 Start1(465,105);
 Start1(585,105);
 Start1(705,105);

 Start2(105,105);  //малюємо горизонтальні полоски для таблиці
 Start2(105,225);
 Start2(105,345);
 Start2(105,465);
 Start2(105,585);
 Start2(105,705);


 Button1->Visible=True; //розблоковуємо кнопки для гри
 Button2->Visible=True;
 Button3->Visible=True;
 Button4->Visible=True;
 Button5->Visible=True;
 Button6->Visible=True;
 Button7->Visible=True;
 Button8->Visible=True;
 Button9->Visible=True;
 Button10->Visible=True;
 Button11->Visible=True;
 Button12->Visible=True;
 Button13->Visible=True;
 Button14->Visible=True;
 Button15->Visible=True;
 Button16->Visible=True;
 Button17->Visible=True;
 Button18->Visible=True;
 Button19->Visible=True;
 Button20->Visible=True;
 Button21->Visible=True;
 Button22->Visible=True;
 Button23->Visible=True;
 Button24->Visible=True;
 Button25->Visible=True;
 Memo1->Visible=True; //розблоковуємо Мемо1
 Memo1->Text = "X_player's turn"; //сповіщення про хід гравця


}
//---------------------------------------------------------------------------
void TForm1::Start1(int w,int h)//малюємо вертикальні полоски для таблиці
{
 Form1->Canvas->MoveTo(w, h);
 Form1->Canvas->LineTo(w,(h-5)*7);
}
void TForm1::Start2(int w,int h)//малюємо горизонтальні полоски для таблиці
{
 Form1->Canvas->MoveTo(w, h);
 Form1->Canvas->LineTo((w-5)*7,h);
}
void __fastcall TForm1::Button1Click(TObject *Sender) //функція при натиску кнопки(для всіх інших все те саме окрім координатних даних та номеру в матриці)
{
  Button1->Visible=False;//блок цієї ж клавіші після натисканні
  if(fl == 1){ //якщо фл=1(хід гравця_Х) то...
   mas[0][0] = fl; // записуємо 1 в масив, що зазначає місце Х на цій точці
   function_to_make_X(105,105,225,225,105,225,225,105);// малюємо Х
   int c = checkwin(0,0);// закидуємо координати точки матриці та перевіряємо на виграш
   if( c == 1){ //сповіщення про виграш гравця_Х
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){  //сповіщення про нічию
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0; // якщо гравець_Х не виграв то передаємо хід гравцю_О
   Memo1->Text = "O_player's turn";
   }
  else{ //якщо фл=0(хід гравця_О) то...
   mas[0][0] = fl; // записуємо 0 в масив, що зазначає місце О на цій точці
   function_to_make_O(115,115,215,215); //малюємо О
   int c = checkwin(0,0); // закидуємо координати точки матриці та перевіряємо на виграш
   if( c == 1){ //сповіщення про виграш гравця_О
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){ //сповіщення про нічию
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1; // якщо гравець_О не виграв то передаємо хід гравцю_Х
   Memo1->Text = "X_player's turn";
  }
}

//---------------------------------------------------------------------------
//функція яка малює Х
void TForm1::function_to_make_X(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
 Form1->Canvas->MoveTo(x1, y1); //Переводимо ручку в лівий верхній кут клітинки
 Form1->Canvas->LineTo(x2 ,y2); //Малюємо палку від лівого верхнього до правого нижнього кута

 Form1->Canvas->MoveTo(x3, y3); //Переводимо ручку в правий верхній кут клітинки
 Form1->Canvas->LineTo(x4 ,y4); //Малюємо палку від правого верхнього до лівого нижнього кута
}
//функція яка малює О
void TForm1::function_to_make_O(int x1, int y1, int x2, int y2)
{
 Form1->Canvas->Ellipse(x1,y1,x2,y2);

}
int TForm1::checkwin(int i, int j) //перевірка на виграш
{
 count++;  //перевірка виконується після того як ставиться знак в клітинку тому
           //кількість перевірок == кількості знаків
 if((i == j) || (i + j == 4)){ //перевірка точок які можуть виграти як діагонально так і вертикально, або ж горизонтально
  if(check_diag(i, j) || check_goriz(i, j) || check_vertical(i, j)) return 1; //якщо виграш то повертає 1
  else if(count == 25) return -1; //якщо всі точки заповнені а переможця немає то повертає -1
  else return 0; //якщо точки ще є та ніхто досі не виграв то повертає 0
 }
 else{//перевірка точок які можуть виграти тільки горизонтально або вертикально
  if(check_goriz(i, j) || check_vertical(i, j)) return 1; //якщо виграш то повертає 1
  else if(count == 25) return -1; //якщо всі точки заповнені а переможця немає то повертає -1
  else return 0; //якщо точки ще є та ніхто досі не виграв то повертає 0
 }
}
int TForm1::check_diag(int i, int j)//перевірка матриці на діагональну перемогу(розглядаємо точку та її по
{
 if((i == j) && (i + j == 4)){ //спеціальна умова для точки в центрі(вона відноситься як і до головної так і до бічної діагоналі)
  int fl2 = 1, fl3 = 1;
  for(int a = 0; a < 5; a++){ //умова для виграшу по головній діагоналі
    if(mas[a][a] != fl){
    fl2 = 0;
    break;
    }
  }
  int b = 4;
  for(int a = 0; a < 5; a++, b--){ //умова для виграшу по бічні діагоналі
    if(mas[a][b] != fl){
    fl3 = 0;
    break;
    }
  }
  if(fl2 || fl3) return 1; //якщо хочаб одна із цих умов виконується то повертаємо 1(перемогу)
  return 0;
 }
 else if(i == j){ // головна діагональ
  for(int a = 0; a < 5; a++){
    if(mas[a][a] != fl) return 0;//якщо існує хочаби одна точка яка не дорівнює теперішньому знаку(фл=1=Х)(фл=0=О) то повертаємо 0
  }
 }
  else if(i + j == 4){ //бічна діагональ
  int b = 4;
  for(int a = 0; a < 5; a++, b--){
   if(mas[a][b] != fl) return 0;//якщо існує хочаби одна точка яка не дорівнює теперішньому знаку(фл=1=Х)(фл=0=О) то повертаємо 0
  }
 }
 return 1;//якщо всі знаки по діагоналі дорівнюють теперішньому то повертаємо 1(перемога по діагоналі)
}
int TForm1::check_goriz(int i, int j)//перевірка матриці на горизонтальну перемогу
{
 for(int a = 0; a < 5; a++){
  if(mas[i][a] != fl) return 0;//якщо існує хочаби одна точка яка не дорівнює теперішньому знаку(фл=1=Х)(фл=0=О) то повертаємо 0
  }
 return 1; //якщо всі знаки по горизонталі дорівнюють теперішньому то повертаємо 1(перемога по горизонталі)
}
int TForm1::check_vertical(int i, int j)//перевірка матриці на вертикальну перемогу
{
 for(int a = 0; a < 5; a++){
  if(mas[a][j] != fl) return 0;//якщо існує хочаби одна точка яка не дорівнює теперішньому знаку(фл=1=Х)(фл=0=О) то повертаємо 0
  }
 return 1; //якщо всі знаки по вертикалі дорівнюють теперішньому то повертаємо 1(перемога по вертикалі)
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Button2->Visible=False;
  if(fl == 1){
   mas[0][1] = fl;
   function_to_make_X(225,105,345,225,225,225,345,105);
   int c = checkwin(0,1);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[0][1] = fl;
   function_to_make_O(235,115,335,215);
   int c = checkwin(0,1);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Button3->Visible=False;
  if(fl == 1){
   mas[0][2] = fl;
   function_to_make_X(345,105,465,225, 345,225,465,105);
   int c = checkwin(0,2);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[0][2] = fl;
   function_to_make_O(355,115,455,215);
   int c = checkwin(0,2);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Button4->Visible=False;
  if(fl == 1){
   mas[0][3] = fl;
   function_to_make_X(465,105,585,225, 465,225,585,105);
   int c = checkwin(0,3);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[0][3] = fl;
   function_to_make_O(475,115,575,215);
   int c = checkwin(0,3);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
Button5->Visible=False;
  if(fl == 1){
   mas[0][4] = fl;
   function_to_make_X(585,105,705,225, 585,225,705,105);
   int c = checkwin(0,4);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[0][4] = fl;
   function_to_make_O(595,115,695,215);
   int c = checkwin(0,4);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Button6->Visible=False;
  if(fl == 1){
   mas[1][0] = fl;
   function_to_make_X(105,225,225,345,105,345,225,225);
   int c = checkwin(1,0);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";

  }
  else{
   mas[1][0] = fl;
   function_to_make_O(115,235,215,335);
   int c = checkwin(1,0);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Button7->Visible=False;
  if(fl == 1){
   mas[1][1] = fl;
   function_to_make_X(225,225,345,345, 225,345,345,225);
   int c = checkwin(1,1);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[1][1] = fl;
   function_to_make_O(235,235, 335,335);
   int c = checkwin(1,1);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
Button8->Visible=False;
  if(fl == 1){
   mas[1][2] = fl;
   function_to_make_X(345,225,465,345, 345,345,465,225);
   int c = checkwin(1,2);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[1][2] = fl;
   function_to_make_O(355,235, 455,335);
   int c = checkwin(1,2);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
Button9->Visible=False;
  if(fl == 1){
   mas[1][3] = fl;
   function_to_make_X(465,225,585,345, 465,345,585,225);
   int c = checkwin(1,3);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[1][3] = fl;
   function_to_make_O(475,235, 575,335);
   int c = checkwin(1,3);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
Button10->Visible=False;
  if(fl == 1){
   mas[1][4] = fl;
   function_to_make_X(585,225,705,345, 585,345,705,225);
   int c = checkwin(1,4);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[1][4] = fl;
   function_to_make_O(595,235, 695,335);
   int c = checkwin(1,4);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
Button11->Visible=False;
  if(fl == 1){
   mas[2][0] = fl;
   function_to_make_X(105,345,225,465, 225,345,105,465);
   int c = checkwin(2,0);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[2][0] = fl;
   function_to_make_O(115,355, 215,455);
   int c = checkwin(2,0);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
Button12->Visible=False;
  if(fl == 1){
   mas[2][1] = fl;
   function_to_make_X(225,345,345,465, 345,345,225,465);
   int c = checkwin(2,1);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[2][1] = fl;
   function_to_make_O(235,355, 335,455);
   int c = checkwin(2,1);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
Button13->Visible=False;
  if(fl == 1){
   mas[2][2] = fl;
   function_to_make_X(345,345,465,465, 465,345,345,465);
   int c = checkwin(2,2);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[2][2] = fl;
   function_to_make_O(355,355, 455,455);
   int c = checkwin(2,2);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
Button14->Visible=False;
  if(fl == 1){
   mas[2][3] = fl;
   function_to_make_X(465,345,585,465, 585,345,465,465);
   int c = checkwin(2,3);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[2][3] = fl;
   function_to_make_O(475,355, 575,455);
   int c = checkwin(2,3);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
Button15->Visible=False;
  if(fl == 1){
   mas[2][4] = fl;
   function_to_make_X(585,345,705,465, 705,345,585,465);
   int c = checkwin(2,4);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[2][4] = fl;
   function_to_make_O(595,355, 695,455);
   int c = checkwin(2,4);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
Button16->Visible=False;
  if(fl == 1){
   mas[3][0] = fl;
   function_to_make_X(105,465,225,585, 225,465,105,585);
   int c = checkwin(3,0);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[3][0] = fl;
   function_to_make_O(115,475, 215,575);
   int c = checkwin(3,0);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";

  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
Button17->Visible=False;
  if(fl == 1){
   mas[3][1] = fl;
   function_to_make_X(225,465,345,585, 345,465,225,585);
   int c = checkwin(3,1);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[3][1] = fl;
   function_to_make_O(235,475, 335,575);
   int c = checkwin(3,1);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
Button18->Visible=False;
  if(fl == 1){
   mas[3][2] = fl;
   function_to_make_X(345,465,465,585, 465,465,345,585);
   int c = checkwin(3,2);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[3][2] = fl;
   function_to_make_O(355,475, 455,575);
   int c = checkwin(3,2);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
Button19->Visible=False;
  if(fl == 1){
   mas[3][3] = fl;
   function_to_make_X(465,465,585,585, 585,465,465,585);
   int c = checkwin(3,3);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[3][3] = fl;
   function_to_make_O(475,475, 575,575);
   int c = checkwin(3,3);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
Button20->Visible=False;
  if(fl == 1){
   mas[3][4] = fl;
   function_to_make_X(585,465,705,585, 705,465,585,585);
   int c = checkwin(3,4);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[3][4] = fl;
   function_to_make_O(585,475, 695,575);
   int c = checkwin(3,4);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
Button21->Visible=False;
  if(fl == 1){
   mas[4][0] = fl;
   function_to_make_X(105,585,225,705, 225,585,105,705);
   int c = checkwin(4,0);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[4][0] = fl;
   function_to_make_O(115,595, 215,695);
   int c = checkwin(4,0);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
Button22->Visible=False;
  if(fl == 1){
   mas[4][1] = fl;
   function_to_make_X(225,585,345,705, 345,585,225,705);
   int c = checkwin(4,1);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[4][1] = fl;
   function_to_make_O(235,595, 335,695);
   int c = checkwin(4,1);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
Button23->Visible=False;
  if(fl == 1){
   mas[4][2] = fl;
   function_to_make_X(345,585,465,705, 465,585,345,705);
   int c = checkwin(4,2);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[4][2] = fl;
   function_to_make_O(355,595, 455,695);
   int c = checkwin(4,2);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
Button24->Visible=False;
  if(fl == 1){
   mas[4][3] = fl;
   function_to_make_X(465,585,585,705, 585,585,465,705);
   int c = checkwin(4,3);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[4][3] = fl;
   function_to_make_O(475,595, 575,695);
   int c = checkwin(4,3);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
Button25->Visible=False;
  if(fl == 1){
   mas[4][4] = fl;
   function_to_make_X(585,585,705,705, 705,585,585,705);
   int c = checkwin(4,4);
   if( c == 1){
   ShowMessage("X_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 0;
   Memo1->Text = "O_player's turn";
  }
  else{
   mas[4][4] = fl;
   function_to_make_O(595,595, 695,695);
   int c = checkwin(4,4);
   if( c == 1){
   ShowMessage("O_player won");
   Form1->Close();
   }
   if(c == -1){
   ShowMessage("Draw");
   Form1->Close();
   }
   fl = 1;
   Memo1->Text = "X_player's turn";
  }
}
//---------------------------------------------------------------------------


