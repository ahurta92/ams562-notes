#include "examples.h"
class No_file:public std::exception {
public:
	virtual int what(){
		cerr<<"No File exception"<<std::endl;
		return -1;
	}
};
void f(fstream *pf){
	*(pf)<<" f() "<<endl;
};
void g(fstream* pf){
	*(pf)<<" g() "<<endl;
}
void user(const string& name, ios_base::openmode mode){
	fstream* fp {new fstream(name,mode)};
	*fp<<"Hello World"<<endl;
	if(!*fp)
		throw No_file{};
	f(fp);
	g(fp);

}
int main() {
	try{
		user("no shared.txt",fstream::out);
	}catch(No_file& z){
		cerr<<z.what()<<endl;
	}
}
