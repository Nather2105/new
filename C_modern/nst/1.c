#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<ctype.h>

void toCap(FILE* old, FILE* new);


int main()
{
  //system("chcp 1251");
  
  FILE* fold;
  FILE* fnew;
  fold = fopen("1.txt", "r");
  if (fold == NULL) {
    printf(" file isn't found");
    return 0;
  }

  fnew = fopen("2.txt", "w");
  toCap(fold, fnew);
  
  fclose(fold); 
  fclose(fnew);
  //printf("%lf\n", aver);
  
  //printf("%d", aver);
  return 0;
}

void toCap(FILE* old, FILE* new) {
  char alf_low[] = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
  char alf_cap[] = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ", * p;
  int sym, nsent = 0;
  while ((sym = fgetc(old)) != EOF) {
    printf("(%d)", sym);
    if (islower(sym) != 0) {
      fputc(toupper(sym), new);
      continue;
    }
    if ((p=strchr(alf_low, sym))!= NULL) {
      fputc(alf_cap[p - alf_low], new);
      continue;
    }
    if (sym == ' ') nsent++;
    
    fputc(sym, new);
  }
}