#include "examples.h"
#include <algorithm>

bool has_c(const string&s,char c){
	auto p=find(s.begin(),s.end(),c);
	if(p!=s.end()){
		return true;
	}else{
		return false;
	}
}

int main(){
	auto name="Adrian"s;
	auto home="Solid"s;
	char c='4';
	char d='i';
	if (has_c(name,c))
		cout<<"name has "<<c<<std::endl;
	if (has_c(name,d))
		cout<<"name has "<<d<<std::endl;
	if (has_c(home,c))
		cout<<"home has "<<c<<std::endl;
	if (has_c(name,d))
		cout<<"home has "<<d<<std::endl;



}

