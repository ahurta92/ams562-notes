#include "examples.h"
#include <algorithm>

bool operator<(const Entry &a,const Entry& b){
	return a.name<b.name;
}
bool operator==(const Entry& a,const Entry& b){
	return (a.name==b.name)&&(a.number==b.number);
}
void f(vector<Entry>& vec,list<Entry>&lst){
	sort(vec.begin(),vec.end(),[](const Entry&a,const Entry&b){return a.number<b.number;});//use < for order
	unique_copy(vec.begin(),vec.end(),lst.begin()); // dont' copy adjacent equal elements
}

int main(){
	auto entries= readFileEntries("entries.txt");
	cout<<entries<<endl;
	list<Entry> only_unique(entries.size());
	f(entries,only_unique);
	cout<<"after sort :"<<endl;

	cout<<entries<<endl;
	cout<<"only uniques:"<<endl;
	cout<<only_unique<<endl;

}

