#include"stdafx.h"

class OBJECT{
protected:
	int x,y;
public:
	OBJECT(){x=0; y=0;}
	OBJECT(int a, int b){x=a; y=b;}
	void show_x(){printf("%d",x);}
	void show_y(){printf("%d",y);}
	int get_x(){return x;}
	int get_y(){return y;}

	virtual void show_class(void)=0;
	virtual void show_tree(void)=0;
	virtual void show_price(void)=0;
	virtual float calc_price(void)=0;
};

class Vehicle: public OBJECT{
protected:
	float price;
public:
	Vehicle(){price=0;}
	Vehicle(int a, int b):OBJECT(a,b){price=0;}
	Vehicle(int z, int a, int b):OBJECT(a,b){price=z;}
};

class Military: public OBJECT{
protected:
	double firepower;
	int ammo;
public:
	Military(){firepower=0; ammo=0;}
	Military(int a, int b):OBJECT(a,b){firepower=0; ammo=0;}
	Military(double pwr, int w, int a, int b):OBJECT(a,b){firepower=pwr; ammo=w;}
};

class Ground: public Vehicle{
protected:
	int weight;
public:
	Ground(){weight=0;}
	Ground(int m, int a, int b):Vehicle(a,b){weight=m;}
	Ground(int m, float z, int a, int b):Vehicle(z,a,b){weight=m;}
};

class Aerial: public Vehicle{
private:
	int fuel;
	double max_height;
public:
	Aerial(){fuel=0; max_height=0;}
	Aerial(int f, double h, int a, int b):Vehicle(a,b){fuel=f; max_height=h;};
	Aerial(int f, double h, float z, int a, int b):Vehicle(z,a,b){fuel=f; max_height=h;}

	float calc_price(){return ((fuel*6)+(max_height*8)+price);}

	void show_class(){printf("This object belongs to the Aerial class\n");}
	void show_tree(){printf("TREE: OBJECT->Vehicle->Aerial\n");}
	void show_price(){printf("This aircraft price is %f\n",calc_price());}
};

class Wheeled: public Ground{
private:
	int topspeed;
public:
	Wheeled(){topspeed=0;}
	Wheeled(int s, int m, int a, int b):Ground(m,a,b){topspeed=s;}
	Wheeled(int s, int m, int z, int a, int b):Ground(m,z,a,b){topspeed=s;}

	float calc_price(){return ((topspeed*10)-(weight));}

	void show_class(){printf("This object belongs to the Wheeled class\n");}
	void show_tree(){printf("TREE: OBJECT->Vehicle->Ground->Wheeled\n");}
	void show_price(){printf("This vehicle price is %f\n",calc_price());}
};

class Crawler: public Ground, public Military{
private:
	int engine_power;
	char type_index;
public:
	Crawler(){engine_power=0; type_index='\0';}
	Crawler(int e, char t, int m, int a, int b):Ground(m,a,b){engine_power=e; type_index=t;}
	Crawler(int e, char t, int m, float z, int a, int b):Ground(m,z,a,b){engine_power=e; type_index=t;}
	Crawler(int e, char t, int m, double pwr, int w, int a, int b):Ground(m,a,b), Military(pwr,w){engine_power=e; type_index=t;}
	Crawler(int e, char t, int m, float z, double pwr, int w, int a, int b):Ground(m,z,a,b), Military(pwr,w){engine_power=e; type_index=t;}

	float calc_price(){return ((firepower*20)+(ammo*2)+price+(engine_power*15)-weight);}

	void show_class(){printf("This object belongs to the Crawler class\n");}
	void show_tree(){printf("TREE: OBJECT->Vehicle->Ground->Crawler<-Military<-OBJECT\n");}
	void show_price(){printf("This thing costs %f\n",calc_price());}
};

void main(void){
int pause=0;

Aerial unit1(100,500,5599,10,10);
Crawler unit2(155,'A',150,4000,90.5,250,5,8);
Wheeled unit3(200,35,600,1,4);

unit1.show_class();
unit1.show_tree();
unit1.show_price();
	printf("\n");

unit2.show_class();
unit2.show_tree();
unit2.show_price();
	printf("\n");

unit3.show_class();
unit3.show_tree();
unit3.show_price();

scanf("%d",pause);
}
