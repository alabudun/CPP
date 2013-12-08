#include"stdafx.h"
#include<stdlib.h>
//\
C-style.
struct pseudo_class{
private:
	double enthusiasm;
	enum oberonOS;
	unsigned *reservation;
	unsigned long long int len;
public:
	pseudo_class(){enthusiasm=0; reservation=NULL; len=0;}
	pseudo_class(unsigned long long int double_tripple){
		printf("Hey! Behold encapsulated structure!\n");
		enthusiasm=200.0;
		len=double_tripple;
		printf("%%Allocating %d unsigned int variables%%\n",len);
		reservation=(unsigned*)malloc(len*sizeof(unsigned));
		for(int C=0; C<len; C++){*(reservation+C)=1+(C*C);}
	}

	void method0(){
		printf("\n%%Printing array%%\n");
		for(int i=0; i<len; i++){printf("%d\n",*(reservation+i));}
	}

	~pseudo_class(){
		printf("Launching destructor. . .\n");
		free(reservation);
		printf("Memory un-allocated!");
	}
};
void main(void){
	char pause[2]={'\0','\0'};
	pseudo_class pseudo_object0(15);

	pseudo_object0.method0();

	scanf("%s",&pause);
(pause[0]=='z')?(printf("\nWa-hey!\n")):(exit(0));
	scanf("%s",&pause);
	return;
}