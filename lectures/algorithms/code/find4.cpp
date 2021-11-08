#include <algorithm>
#include "examples.h"
#include "findall2.h"

int main()
{
	auto m = "Mary had a little lamb"s;
	for (auto p:find_all(m,'a')){
		if(*p!='a')
			cerr<<"string bug!!!\n";
	}
	list<double> ld{1.1,2.3,3.3,1.1};
	for (auto p:find_all(ld,1.1)){
		if(*p!=1.1)
			cerr<<"list bug!\n";
	}
	vector<string> vs{"red","blue","green","green","orange","green"};
	for(auto p:find_all(vs,"red")){
		if(*p!="red")
			cerr<<"vector bug"<<endl;

	}
	cout<<vs;
	cout<<"find and replace: "<<endl;
	for(auto p : find_all(vs, "green"))
		*p = "purple";
	cout<<vs;




}
