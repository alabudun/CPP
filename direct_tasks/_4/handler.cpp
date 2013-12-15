#include"stdafx.h"
#include<iostream>

using namespace std;

#include"handler.h"
#include"vector.h"
#include<fstream>

void System::shutdown(){
	cout<<endl;
	system("pause");
	exit(0);
}

void System::mainpage(/*void *slot, char type[]*/){
	cout<<"Here you can see vector list:\n";
	//if(type[0]=='?') cout<<"EMPTY";
}

void System::errorlist(){
	char x;
	cout<<"Possible errors and their codes:\n\n";
	ifstream input("exceptions.txt");
		while(input.peek()!=EOF){
			input.get(x);
			if(x=='$'){input.ignore(150,'\n'); continue;}
			cout<<x;
		}
		input.close();
}

void System::l_arrow(System &s){
	(s.selector>0)?(s.selector--):(s.selector+=4);
}

void System::r_arrow(System &s){
	(s.selector<4)?(s.selector++):(s.selector-=4);
}

void System::enter(System &s){
	char x;
	if(s.selector==4)
		exit(0);
	if(s.selector==3){
		ifstream input("log.txt");
		while(input.peek()!=EOF){
			input.get(x);
			cout<<x;
		}
		input.close();
	}
	if(s.selector==2){
		s.errorlist();
	}
	if(s.selector==1){
		s.freezed=true;
	}
	if(s.selector==0){
		s.freezed=true;
			char x[11];
			char choice;
			int length;
			int slot;

			cout<<"Choose slot>>";
			cin>>slot;
			cout<<endl;

			cout<<"Define vector type>>";
			try{
			cin>>x; 
			if(!(strcmp(x,"int")==0 || strcmp(x,"float")==0 || strcmp(x,"double")==0)) throw EM_typedef();
			}
			catch(EM_typedef &e){e.alert();}
			cout<<endl;
			
			cout<<"Input vector length>>";
			cin>>length;
if(strcmp(x,"int")==0)
Vector<int> vect0(length);	
			cout<<"\nDo you want to input all values manually (y/n)?>>";
			cin>>choice;


		s.freezed=false;
	}
}
//E_Fatal
E_Fatal::E_Fatal(int arg):crush(arg){}

void E_Fatal::alert(){
	cout<<"handler: critical error occured. Terminating console.\n";
	system("pause");
	exit(crush);
}

//EM_indexation <minor error ¹1>
EM_indexation::EM_indexation(){e_code=375;}

void EM_indexation::alert(){
	printf("handler: minor error occured. Error code: %d.\n", e_code);
	cout<<"%%handler will now perform required operations%%\n";
}
//EM_typedef
EM_typedef::EM_typedef(){e_code=119;}

void EM_typedef::alert(){
	printf("handler: minor error occured. Error code: %d.\n", e_code);
}