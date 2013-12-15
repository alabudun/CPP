#pragma once
//CONTROLLER
class System{
private:
	bool freezed;
	int selector;
	char *content[3];
public:
	System(){
		freezed=false;
		selector=0;

		content[0]=new char[(strlen("Main page."))];
		strcpy(content[0],"Main page.");
		content[1]=new char[(strlen("Creating a new vector."))];
		strcpy(content[1],"Creating a new vector.");
		content[2]=new char[(strlen("Viewing an existing vector."))];
		strcpy(content[2],"Viewing an existing vector.");
		content[3]=new char[(strlen("Browsing handler library."))];
		strcpy(content[3],"Browsing handler library.");
		content[4]=new char[(strlen("Exploring log.txt."))];
		strcpy(content[4],"Exploring log.txt.");
	}

	void mainpage(/*void*, char[]*/);
	void errorlist();

	void shutdown();
	void l_arrow(System&);
	void r_arrow(System&);
	void enter(System&);

	bool is_freezed(){return freezed;}
	int get_selector(){return selector;}
	char* get_string(int arg){return content[arg];}

	~System(){
		delete []content;
	}
};
//ERROR HANDLERS
class Error{
protected:
	int e_code;
public:
	virtual void alert()=0;
};

class E_Fatal: public Error{
private:
	int crush;
public:
/**/E_Fatal(int);
	void alert();
};

class E_Minor: public Error{
public: //log update methods here
};

class EM_indexation: public E_Minor{
public:
/**/EM_indexation();
	void alert();
};

class EM_typedef: public E_Minor{
public:
	EM_typedef();
	void alert();
};