//\
[summit]->[left_edge]->[true_class]<-[right_edge]<-[summit]
#include"stdafx.h"
#include<iostream>

class SUMMIT{
protected:
	int z;
public:
	SUMMIT(){z=1;}
};

class Left_Edge: public SUMMIT{
protected:
	int x;
public:
	Left_Edge(){x=2;}
};

class Right_Edge: public SUMMIT{
protected:
	int y;
public:
	Right_Edge():y(3){}
};

class True_Class: public Left_Edge, public Right_Edge{
protected:
public:
	void show(){std::cout<<Left_Edge::z<<"...("<<x<<';'<<y<<')'<<std::endl;}
};

class Quasi_Class: public True_Class{
protected:
public:
	void show(){std::cout<<Right_Edge::z<<"...("<<x<<';'<<y<<')'<<std::endl;}
};

void main(void){
	int selector;

	True_Class object0;
	Quasi_Class object1;

	std::cout<<">>"; std::cin>>selector;

	(selector==1)?object0.show():object1.show();

std::system("pause");
return;

}