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
	int set(int v){this->val=v;}
	~X()=default;
private:
	int val=0;
};

template<typename T>
std::unique_ptr<T> returnPointer(){
	std::unique_ptr<T> ptr {new T[100000]};
	T v=0;
	std::unique_ptr<T> ptr1{new T("hello")};
	T* tt=&(*ptr);
	for(int i=0; i<100000; i++){
		tt->set(i);
		tt++;
	}

	 //ptr= new T(std::string("hello"));
	return ptr;// error return a stack allocated variable
}

std::ostream &operator<<(std::ostream &os, const X x){
	std::cout<<x.get()<<std::endl;
}



int main(){

	int p;
	int parray[1000];
	std::cout<<parray<<std::endl;
	std::cout<<*parray<<std::endl;
	std::cout<<*(parray+1)<<std::endl;
	std::cout<<&parray[0]<<std::endl;
	std::cout<<parray[0]<<std::endl;
	std::cout<<&parray[1]<<std::endl;
	std::cout<<parray[1]<<std::endl;
	std::cout<<parray[2]<<std::endl;
	std::cout<<parray[3]<<std::endl;

	int size_array=10;
	int* ptr=new int[size_array];// allocates memory on the heap

	for(int i=0; i<size_array; i++){
		ptr[i]=i;
		std::cout<<*&ptr[i]<<"\n";
	}




	auto x=returnPointer<X>();

}



