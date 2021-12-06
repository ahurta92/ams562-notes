#include "examples.h"


ostream& operator<<(ostream& os, const vector<Entry> & v){
	for(const auto& entry : v){
		os<<entry<<endl;
	}
	return os;

}
int main(){

	vector<Entry> vE;

	ifstream entry_file;
	entry_file.open("entries.txt");
	if(entry_file){
		entry_file>>vE;
	}else{
		cout<<"did not read"<<endl;
	}
	cout<<vE;



}