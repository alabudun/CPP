#include"stdafx.h"
#include"virtual_mouse.h"
#include"ascii_draw.h"
#include"wanderer.h"
#include<iostream>
#include<Windows.h>
using namespace std;

void draw(char s[]){ system("CLS");
	for(int i=0; i<15; i++, cout<<endl)
		for(int j=0; j<25; j++)
			cout<<s[(i*25)+j];
}

char symb(int tool, char s[], bool &sta, bool &fin, int ax, int ay, int &sx, int &sy, int &fx, int &fy){

	if(tool==0){
		if(sta==true && s[sx+(sy*25)]==' ') s[sx+(sy*25)]='.'; else sta=true;
			sx=ax;
			sy=ay;

	return ' ';
	}

	if(tool==1){
		if(fin==true && s[fx+(fy*25)]=='F') s[fx+(fy*25)]='.'; else fin=true;
			fx=ax;
			fy=ay;

	return 'F';
	}

	if(tool==2) return '#';
	if(tool==3) return '.';
}

class Cell{
protected: 
	int x, y;
	char image;
public:
	Cell(){}
	Cell(int x_, int y_){x=x_; y=y_;}

	int g_x(){return x;}
	int g_y(){return y;}
    char g_g(){return image;}	
};

class Mobile: public Cell{
private:
	int direction;
	int prior[4];
public:
	Mobile(char img, int x_, int y_):Cell(x_, y_){image=img; direction=-1;}
void set_xy(int x_, int y_){x=x_; y=y_;}
	void mov(char s[]){get_dir(s);
		s[x+(y*25)]=' ';
	if(direction==0){if(s[(x+1)+(y*25)]!='#') x++;}
	if(direction==1){if(s[(x)+((y-1)*25)]!='#') y--;}
	if(direction==2){if(s[(x-1)+(y*25)]!='#') x--;}
	if(direction==3){if(s[(x)+((y+1)*25)]!='#') y++;}
	get_dir(s);
		s[x+(y*25)]=image;
}
	
	void get_dir(char s[]){int p2count=0, p1count=0, dice;
	for(int i=0; i<4; i++) prior[i]=0;
	if(((s[(x+1)+(y*25)]!='#' && s[(x+1)+(y*25)]!=' ') || s[(x+1)+(y*25)]=='F') && direction!=2) prior[0]=2;
	if(((s[x+((y-1)*25)]!='#' && s[x+((y-1)*25)]!=' ') || s[x+((y-1)*25)]=='F') && direction!=3) prior[1]=2;
	if(((s[(x-1)+(y*25)]!='#' && s[(x-1)+(y*25)]!=' ') || s[(x-1)+(y*25)]=='F') && direction!=0) prior[2]=2;
	if(((s[x+((y+1)*25)]!='#' && s[x+((y+1)*25)]!=' ') || s[x+((y+1)*25)]=='F') && direction!=1) prior[3]=2;
	if(s[(x+1)+(y*25)]==' ' && direction!=2) prior[0]=1;
	if(s[x+((y-1)*25)]==' ' && direction!=3) prior[1]=1;
	if(s[(x-1)+(y*25)]==' ' && direction!=0) prior[2]=1;
	if(s[x+((y+1)*25)]==' ' && direction!=1) prior[3]=1;
	for(int i=0; i<4; i++){if(prior[i]==2) p2count++;}
	if(p2count==1){if(prior[0]==2) {direction=0; return;} if(prior[1]==2) {direction=1; return;} if(prior[2]==2) {direction=2; return;} if(prior[3]==2) {direction=3; return;}}
	if(p2count>=2){dice=rand()%p2count; for(int i=0; i<4; i++){if(prior[i]==2 && dice==0) {direction=i; return;} if(prior[i]==2) dice-=1;}}
for(int i=0; i<4; i++){if(prior[i]==1) p1count++;}
	if(p1count==1){if(prior[0]==1) {direction=0; return;} if(prior[1]==1) {direction=1; return;} if(prior[2]==1) {direction=2; return;} if(prior[3]==1) {direction=3; return;}}
	if(p1count>=2){dice=rand()%p1count; for(int i=0; i<4; i++){if(prior[i]==1 && dice==0) {direction=i; return;}; if(prior[i]==1) dice-=1;}}

	if(p2count==0 && p1count==0){
	if((s[(x+1)+(y*25)]!='#' && s[(x+1)+(y*25)]!=' ')) prior[0]=2;
	if((s[x+((y-1)*25)]!='#' && s[x+((y-1)*25)]!=' ')) prior[1]=2;
	if((s[(x-1)+(y*25)]!='#' && s[(x-1)+(y*25)]!=' ')) prior[2]=2;
	if((s[x+((y+1)*25)]!='#' && s[x+((y+1)*25)]!=' ')) prior[3]=2;
	if(s[(x+1)+(y*25)]==' ') prior[0]=1;
	if(s[x+((y-1)*25)]==' ') prior[1]=1;
	if(s[(x-1)+(y*25)]==' ') prior[2]=1;
	if(s[x+((y+1)*25)]==' ') prior[3]=1;
	if(p2count==1){if(prior[0]==2) {direction=0; return;} if(prior[1]==2) {direction=1; return;} if(prior[2]==2) {direction=2; return;} if(prior[3]==2) {direction=3; return;}}
	if(p2count>=2){dice=rand()%p2count; for(int i=0; i<4; i++){if(prior[i]==2 && dice==0) {direction=i; return;} if(prior[i]==2) dice-=1;}}
for(int i=0; i<4; i++){if(prior[i]==1) p1count++;}
	if(p1count==1){if(prior[0]==1) {direction=0; return;} if(prior[1]==1) {direction=1; return;} if(prior[2]==1) {direction=2; return;} if(prior[3]==1) {direction=3; return;}}
	if(p1count>=2){dice=rand()%p1count; for(int i=0; i<4; i++){if(prior[i]==1 && dice==0) {direction=i; return;}; if(prior[i]==1) dice-=1;}}
	}
}

	

};

class Static: public Cell{
public:
	Static(int x_, int y_):Cell(x_, y_){image='#';}
};



void main(void)
{
	setlocale(LC_ALL, "rus");
	draw_mm();
	int ax,ay,vm_code, tool=0, sx=0, sy=0, fx, fy, iterations=0;
	char map[25*15], t_out[80*15];
	bool vm_pressed=false, vm_respond=false, c_start=false, c_finish=false;
	Mobile bot(258,0,0);

for(int i=0; i<25*15; i++) map[i]='#';
for(int i=0; i<60*15; i++) t_out[i]=' ';
t_out[60*15]='\0';

while(!(!true))
{
main_menu:
	vm_absolute(ax,ay);
	vm_cycle(vm_code,vm_pressed,vm_respond);
	if((ay>=12 && ay<=14) && (ax<=24) && (vm_respond==true)) exit(0);
	if((ay>=0 && ay<=2) && (ax<=23) && (vm_respond==true)) {draw_l1(map, t_out); goto lb_custom0;}
}

while(!(!true))
{
lb_custom0:
	vm_absolute(ax,ay);
	vm_cycle(vm_code,vm_pressed,vm_respond);
	if(ax<25 && (vm_respond==true)) {map[ax+(ay*25)]=symb(tool, map, c_start, c_finish, ax, ay, sx, sy, fx, fy); draw_l1(map, t_out);}
	if((ay==3) && (ax>=26 && ax<=58) && (vm_respond==true)) {tool=0;}
	if((ay==5) && (ax>=26 && ax<=58) && (vm_respond==true)) {tool=1;}
	if((ay==7) && (ax>=26 && ax<=58) && (vm_respond==true)) {tool=2;}
	if((ay==9) && (ax>=26 && ax<=58) && (vm_respond==true)) {tool=3;}
	if((ay==11) && (ax>=26 && ax<=58) && (vm_respond==true)) {map[sx+(sy*25)]=258; bot.set_xy(sx,sy); draw_l2(map,iterations); goto lb_custom1;}
	if((ay==13) && (ax>=26 && ax<=58) && (vm_respond==true)) {draw_mm(); goto main_menu;}
}

while(!(!true))
{
lb_custom1:
	vm_absolute(ax,ay);
	bot.mov(map);
	
	Sleep(150);
	draw_l2(map,iterations);
	Sleep(150);
	if(bot.g_x()==fx && bot.g_y()==fy) {cout<<endl; system("pause"); break;}
}
//Mobile player(0,0); map[player.g_x()+(player.g_y()*30)]=player.g_g();
//Static e1(3,5); map[e1.g_x()+(e1.g_y()*30)]=e1.g_g();
//Static e2(3,0); map[e2.g_x()+(e2.g_y()*30)]=e2.g_g();
	cout<<endl;
}