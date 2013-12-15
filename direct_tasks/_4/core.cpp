//\
half-done version
#include"stdafx.h"
#include<iostream>
using namespace std;

#include"vector.h"
#include"handler.h"
#include"draw.h"

#include<fstream>
#include<conio.h>

/*template<typename TN>void Vector<TN>::test(){
	cout<<"Hello, void!\n";
}*/

void heading(System &CMD, int arg=1){
	moveOut(0,6);
	cout<<CMD.get_string(CMD.get_selector()+arg);
	moveOut(0,8);
}

int main(char c, char k_event){
/*char slot_types[4]={'?','?','?','?'};
void *slot[4];
for(int i=0; i<4; i++) slot[i]=NULL;*/

	System command;
	colorS(1);

ifstream input("menu.txt");

	while(input.peek()!=EOF){
		input.get(c);
	if(c!='\n')
		prinT(c);
	}
	input.close();

	colorS();
	refresH(command);
	heading(command,0);
	command.mainpage(/*slot,slot_types*/);
	while(true){
	k_event=getch();

		if(k_event==13){
			cleaneR();
			heading(command);
			command.enter(command);
		}
		if(k_event==75){
			if(!command.is_freezed()){
			command.l_arrow(command);
			refresH(command);
			}
		}
		if(k_event==77){
			if(!command.is_freezed()){
			command.r_arrow(command);
			refresH(command);
			}
		}


	}

command.shutdown();
return 0;
}
