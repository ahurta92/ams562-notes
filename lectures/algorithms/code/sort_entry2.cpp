#include "examples.h"
#include <algorithm>

bool operator<(const Entry &a,const Entry& b){
	return a.name<b.name;
}
bool operator==(const Entry& a,const Entry& b){
	return (a.name==b.name)&&(a.number==b.number);
}
list<Entry> f(vector<Entry>& vec){
	list<Entry> res;
	sort(vec.begin(),vec.end());//use < for order
	unique_copy(vec.begin(),vec.end(),back_inserter(res)); // dont' copy adjacent equal elements
	return res;
}

int main(){
	auto entries= readFileEntries("entries.txt");
	cout<<entries<<endl;
	auto only_uniques=f(entries);
	cout<<"after sort :"<<endl;

	cout<<entries<<endl;
	cout<<"only uniques:"<<endl;
	cout<<only_uniques<<endl;

}

