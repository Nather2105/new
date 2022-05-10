#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<ctype.h>


void toCap(FILE* old, FILE* new);
double Aver(FILE* fp);
void Ukr(int* sym1, int* sym2);

int main()
{
	//system("chcp 1251");
	
	FILE* fold;

	fold = fopen("1.txt", "r");
	if (fold == NULL) {
		printf(" file isn't found");
		return 0;
	}
	printf("average amount of letters in word is %.0lf", Aver(fold));
	rewind(fold);

	FILE* fnew;
	fnew = fopen("2.txt", "w");
	toCap(fold, fnew);
	
	fclose(fold);	fclose(fnew);

	return 0;
}

void toCap(FILE* old, FILE* new) {
	int sym, sym2, nsent = 0;
	while ((sym = fgetc(old)) != EOF) {
		if (islower(sym) != 0) {
			fputc(toupper(sym), new);
			continue;
		}
		if (sym == 208 || sym == 209 || sym == 210) {
			sym2 = fgetc(old);
			Ukr(&sym, &sym2);
			fputc(sym, new); fputc(sym2, new);
			continue;
		}
		if (sym == '.') nsent++;
		fputc(sym, new);
		if (nsent == 5) break;
	}	
}

double Aver(FILE* fp) {
	int nword = 1, nlet = 0;
	int sym;
	while ((sym = fgetc(fp)) != EOF) {
		if (sym == ' ') nword++;
		if ((sym >=97 && sym <=122 )||(sym>= 65 && sym<= 90)) nlet++;
		if (sym == 208 || sym == 209 || sym == 210) nlet++;
	}
	return (double)nlet / (double)nword;
}

void Ukr(int* sym1, int* sym2) {
	if (*sym1 == 208) {
		if (*sym2 >= 176 && *sym2 <= 191) 
			*sym2 -= 32;	
	}
	if (*sym1 == 209) {
		if (*sym2 >= 128 && *sym2 <= 143) 
			*sym2 = *sym2 + 32;
		if (*sym2 >= 148 && *sym2 <= 151) 
			*sym2 = *sym2 - 16;
		*sym1 = 208;
	}
	if (*sym1 == 210) 
		*sym2 -= 1;
	
}