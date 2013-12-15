#include<Windows.h>

void moveOut(const int &x=0, const int &y=9){
	HANDLE hConOut=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc={x,y};
	SetConsoleCursorPosition(hConOut, loc);
}

void cleaneR(int y=6, int cycles=10){
	for(int i=0; i<cycles; i++){
		moveOut(0,y+i);
		for(int j=0; j<80; j++){
			cout<<' ';
		}
	}
}

void colorS(int background=0, int text=15){
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void draW(int x, int y, char c[]){
	moveOut(x,y);
	cout<<c;
}

void refresH(System &s){
	if(s.get_selector()==0) colorS(1,10); else colorS(1,15);
	draW(5,2,"New Vector");
	if(s.get_selector()==1) colorS(1,10); else colorS(1,15);
	draW(20,2,"Get Vector");
	if(s.get_selector()==2) colorS(1,10); else colorS(1,15);
	draW(34,2,"Known Errors");
	if(s.get_selector()==3) colorS(1,10); else colorS(1,15);
	draW(51,2,"Show Log");
	if(s.get_selector()==4) colorS(1,10); else colorS(1,15);
	draW(65,2,"To Windows");

	colorS();
	moveOut();
}

void prinT(char &c){
//re-write this part using switch design
	if(c=='!' || c=='\n') return;

	if(c=='-') c=205;
	if(c=='^') c=202;
	if(c=='|') c=186;
	if(c=='/') c=188;
	if(c=='\\') c=200;
	if(c=='@') c=177;

	cout<<c;
}