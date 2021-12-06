#include <memory>
#include <iostream>
#include <string>

class X{
public:
	X()=default;
	X(int s):val{s}{};
	X(std::string s):val{3}{};
	int get(){return val;}
	int get()const{return val;}
private:
	int val=0;
};

template<typename T>
T* returnPointer(){
	T* ptr= new T[100000];
	 ptr= new T(std::string("hello"));
	return ptr;// error return a stack allocated variable
}

std::ostream &operator<<(std::ostream &os, const X x){
	os<<x.get()<<std::endl;
	return os;
}


int main(){


	std::cout<<*(returnPointer<X>());

}



