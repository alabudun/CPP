#include"stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

void draw_mm(void){

	system("CLS");
	cout<<" "; for(int i=0; i<22; i++) cout<<"-";
	cout<<"\n|Лабиринт: свой уровень|\n"; cout<<" "; for(int i=0; i<22; i++) cout<<"-"; cout<<"\n\n";
	cout<<" "; for(int i=0; i<27; i++) cout<<"-";
	cout<<"\n|Лабиринт: случайный уровень|\n"; cout<<" "; for(int i=0; i<27; i++) cout<<"-"; cout<<"\n\n";
	cout<<" "; for(int i=0; i<41; i++) cout<<"-";
	cout<<"\n|Максимальная цена пути: случайный уровень|\n"; cout<<" "; for(int i=0; i<41; i++) cout<<"-"; cout<<"\n\n";
	cout<<" "; for(int i=0; i<23; i++) cout<<"-";
	cout<<"\n|Закрыть консольное окно|\n"; cout<<" "; for(int i=0; i<23; i++) cout<<"-"; cout<<"\n\n";
}

void draw_l1(char s[], char t[]){
	char box1[35]="Инструменты:";
	char box2[35]="Разместить стартовую позицию";
	char box3[35]="Разместить финиш";
	char box4[35]="Разместить стену";
	char box5[35]="Очистить клетку";
	char box6[35]="СТАРТ";
	char box7[35]="Назад в главное меню";

	for(int i=0; i<15; i++){
		for(int j=0; j<60; j++){
			if(j<25) t[(i*60)+j]=s[(i*25)+j];
			if(j>25 && (i==0 || i==14 || i==10)) t[(i*60)+j]=271;
			if((j>25 && j<26+strlen(box1)+((33-strlen(box1))/2)) && (i==1)) {if((j>((33-strlen(box1))/2)+25)) t[(i*60)+j]=box1[j-(26+((33-strlen(box1))/2))];}
			if((j>25 && j<26+strlen(box2)+((33-strlen(box2))/2)) && (i==3)) {if((j>((33-strlen(box2))/2)+25)) t[(i*60)+j]=box2[j-(26+((33-strlen(box2))/2))];}
			if((j>25 && j<26+strlen(box3)+((33-strlen(box3))/2)) && (i==5)) {if((j>((33-strlen(box3))/2)+25)) t[(i*60)+j]=box3[j-(26+((33-strlen(box3))/2))];}
			if((j>25 && j<26+strlen(box4)+((33-strlen(box4))/2)) && (i==7)) {if((j>((33-strlen(box4))/2)+25)) t[(i*60)+j]=box4[j-(26+((33-strlen(box4))/2))];}
			if((j>25 && j<26+strlen(box5)+((33-strlen(box5))/2)) && (i==9)) {if((j>((33-strlen(box5))/2)+25)) t[(i*60)+j]=box5[j-(26+((33-strlen(box5))/2))];}
			if((j>25 && j<26+strlen(box6)+((33-strlen(box6))/2)) && (i==11)) {if((j>((33-strlen(box6))/2)+25)) t[(i*60)+j]=box6[j-(26+((33-strlen(box6))/2))];}
			if((j>25 && j<26+strlen(box7)+((33-strlen(box7))/2)) && (i==13)) {if((j>((33-strlen(box7))/2)+25)) t[(i*60)+j]=box7[j-(26+((33-strlen(box7))/2))];}
			if(j>25 && i==2) t[(i*60)+j]='=';
			if(j>25 && i==4) t[(i*60)+j]='-';
			if(j>25 && i==6) t[(i*60)+j]='-';
			if(j>25 && i==8) t[(i*60)+j]='-';
			if(j>25 && i==12) t[(i*60)+j]='-';
		}
		t[(i*60)+25]=166;
		t[(i*60)+59]=166;
	}
system("CLS");
	for(int i=0; i<15; i++, cout<<endl){
		for(int j=0; j<60; j++)
			cout<<t[(i*60)+j];
	}
}

void draw_l2(char s[], int &i){
system("CLS");
	for(int i=0; i<15; i++, cout<<endl){
		for(int j=0; j<25; j++)
			cout<<s[(i*25)+j];
	}
	cout<<"Number of iterations:"<<i; i++;
}