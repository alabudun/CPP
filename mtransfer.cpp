#include"stdafx.h"
#include<iostream>
using namespace std;

class MATRIX{
protected:
	int h,w;
	char *cell;
public:
	MATRIX(int height, int width){
		h=height;
		w=width;
		cell=new char[h*w];
		for(int i=0; i<h*w; i++){*(cell+i)='a';}
	}
	MATRIX(){
		h=1;
		w=1;
		cell=new char;
		*cell='a';
	}

int gh(){return h;}
int gw(){return w;}
char* gc(){return cell;}

	friend MATRIX operator+(MATRIX &m0, MATRIX &m1);
	friend ostream &operator<<(ostream &s, MATRIX m);
	friend istream &operator>>(istream &s, MATRIX &m);
	void show_int(){
		for(int i=0; i<h; i++, cout<<endl){
			for(int j=0; j<w; j++){
				cout<<'['<<int(*(cell+(w*i)+j))<<']';
			}
		}
	}

virtual ~MATRIX(){delete []cell;}
};

MATRIX operator+(MATRIX &m0, MATRIX &m1){
	MATRIX tmp=m0;
	if((m0.gh()!=m1.gh()) || (m0.gw()!=m1.gw()))
		return tmp;
}

ostream &operator<<(ostream &s, MATRIX m){
	for(int i=0; i<m.gh(); i++, s<<endl){
			for(int j=0; j<m.gw(); j++){
				s<<'|'<<*(m.gc()+(m.gw()*i)+j)<<'|';
			}
		}
	return s;
}

istream &operator>>(istream &s, MATRIX &m){
	for(int i=0; i<m.gh(); i++){
			for(int j=0; j<m.gw(); j++){
				cout<<'['<<i+1<<"]["<<j+1<<"]:";
				s>>*(m.gc()+(m.gw()*i)+j);
			}
		}
	return s;
}

void main(/*BEGIN*/)
{
	MATRIX m1(1,3);
	MATRIX m2(2,3);
	m1.show_int();cout<<endl;
	m2.show_int();cout<<endl;
	m1+m2;
	m1.show_int();cout<<endl;
	m2.show_int();cout<<endl;
	
	system("pause");
}