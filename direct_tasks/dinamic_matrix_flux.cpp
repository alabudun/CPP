//\
alabudun
#include"stdafx.h"
#include<iostream>
using namespace std;

class MATRIX{
protected:
	int h,w;
	int *cell;
public:
	MATRIX(int height, int width){
		h=height;
		w=width;
		cell=new int[h*w];
		for(int i=0; i<h*w; i++)
			*(cell+i)=0;
	}
	MATRIX(){
		h=1;
		w=1;
		cell=new int;
		*cell=0;
	}

int gh(){return h;}
int gw(){return w;}
int* gc(){return cell;}

void fill(int x){
	for(int i=0; i<h*w; i++)
		*(cell+i)=x;
}

	MATRIX operator=(MATRIX b){
	int h_lim, w_lim;
		(h>b.h)?(h_lim=b.h):(h_lim=h);
		(w>b.w)?(w_lim=b.w):(w_lim=w);

		for(int i=0; i<h_lim; i++){
			for(int j=0; j<w_lim; j++){
				*(cell+(w*i)+j)=*(b.cell+(b.w*i)+j);
			}
		}
		return *this;
	}
	friend MATRIX operator+(MATRIX m0, MATRIX m1);
	friend ostream &operator<<(ostream &s, MATRIX m);
	friend istream &operator>>(istream &s, MATRIX &m);
	void show_int(){
		for(int i=0; i<h; i++, cout<<endl){
			for(int j=0; j<w; j++){
				cout<<'['<<int(*(cell+(w*i)+j))<<']';
			}
		}
	}

//virtual ~MATRIX(){cout<<"\n<LAUNCHING DESTRUCTOR!>\n";delete []cell;}
};

MATRIX operator+(MATRIX m0, MATRIX m1){
	MATRIX temp(m0.h,m0.w);
        if((m0.h!=m1.h) || (m0.w!=m1.w))
			return temp;
		else{
			for(int i=0; i<m0.h; i++, cout<<endl){
				for(int j=0; j<m0.w; j++){
					*(temp.cell+(temp.w*i)+j)=(*(m0.cell+(m0.w*1)+j))+(*(m1.cell+(m1.w*1)+j));
				}
			}
			return temp;
		}
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

class sqMATRIX: public MATRIX{
public:
	sqMATRIX(int dimension):MATRIX(dimension, dimension){}
};

void main(/*BEGIN*/)
{
	MATRIX m1(4,4);
	MATRIX m2(2,2);
	sqMATRIX m3(3);
	m3.fill(7);
	cout<<m1;cout<<endl;
	cout<<m2;cout<<endl;
	cout<<m3;cout<<endl;
  /*
    m1=m2;
	cout<<m1;cout<<endl;
	cout<<m2;cout<<endl;
	m1.fill(2);
	cout<<m1;cout<<endl;
	cout<<m2;cout<<endl;
  */
	system("pause");
}