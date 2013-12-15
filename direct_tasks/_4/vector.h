#pragma once

template<typename TN> class Vector{
private:
	TN *v_first;
	int n;
public:
	Vector(){
		n=0;
		v_first=NULL;
	}
	Vector(int arg){
		n=arg;
		v_first=new TN[n];
		for(int i=0; i<n; i++){*(v_first+i)=0;}
	}

	TN operator[](int i){
		cout<<'['<<i<<"]=";
		return *(v_first+i);
	}

	Vector operator+(Vector r_oper){
		Vector l_oper(this->n);
		int i=0;
		while(i<l_oper.n && i<r_oper.n){
			*(l_oper.v_first+i)+=*(r_oper.v_first+i)+*(this->v_first+i);
			i++;
		}
		return l_oper;
	}

	Vector operator=(Vector that){
		int i=0;
		while(i<this->n && i<that.n){
			*(this->v_first+i)=*(that.v_first+i);
			i++;
		}
		return *this;
	}

	friend ostream &operator<</*Tmpl*/<>(ostream &ostr, Vector<TN> operand);
	friend istream &operator>>/*Tmpl*/<>(istream &istr, Vector<TN> &operand);
//void test();
};

template<typename TN>inline istream &operator>>(istream &istr, Vector<TN> &operand){
	for(int i=0; i<operand.n; i++){
		cout<<'['<<i<<"]>>";
		istr>>*(operand.v_first+i);
	}
	return istr;
}

template<typename TN>__forceinline ostream &operator<<(ostream &ostr, Vector<TN> operand){
	for(int i=0; i<operand.n; i++){
		cout<<'['<<i<<"]=";
		ostr<<*(operand.v_first+i)<<endl;
	}
	return ostr;
}