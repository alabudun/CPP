#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;
POINT mouse;
HWND cwind=GetConsoleWindow();
RECT border;

void vm_absolute(int &c1, int &c2){
	GetWindowRect(cwind, &border);
    GetCursorPos(&mouse);
	c1=(mouse.x-border.left-10)/8;
	c2=(mouse.y-border.top-32)/12;
}

void vm_cycle(int &vm_key, bool &pressed, bool &respond){
	vm_key=0;
	if(pressed==false) vm_key=GetKeyState(VK_LBUTTON);
	if(vm_key==-128 || vm_key==-127 && pressed==false)
	{respond=true; vm_key=0; pressed=true;}
	else respond=false;

	vm_key=GetKeyState(VK_LBUTTON);
	if(pressed==true && (vm_key!=-128 && vm_key!=-127)) pressed=false;
	}