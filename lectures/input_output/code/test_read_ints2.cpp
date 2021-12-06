#include "examples.h"

int main(){
	try{
		auto v_ints=read_ints(cin,"stop");
		if(cin.fail()){
			throw std::ios_base::failure("Read something other than stop");
		}
		cout<<v_ints<<endl;
	}catch(std::ios_base::failure& f){
		cerr<<"Terminated without stop"<<endl;
	}
}
