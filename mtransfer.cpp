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

int �h(){return h;}
int �w(){return w;}
char* �c(){return cell;}

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
	if((m0.�h()!=m1.�h()) || (m0.�w()!=m1.�w()))
		return tmp;
}

ostream &operator<<(ostream &s, MATRIX m){
	for(int i=0; i<m.�h(); i++, s<<endl){
			for(int j=0; j<m.�w(); j++){
				s<<'|'<<*(m.�c()+(m.�w()*i)+j)<<'|';
			}
		}
	return s;
}

istream &operator>>(istream &s, MATRIX &m){
	for(int i=0; i<m.�h(); i++){
			for(int j=0; j<m.�w(); j++){
				cout<<'['<<i+1<<"]["<<j+1<<"]:";
				s>>*(m.�c()+(m.�w()*i)+j);
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