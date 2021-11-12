#include <algorithm>
#include "examples.h"
vector<string::iterator> find_all(string& s, char c)
{
	vector<string::iterator> res;
	for(auto p = s.begin(); p != s.end(); ++p)
	{
		if(*p==c){
			res.push_back(p);
		}
	}
	return res;
}
int main()
{
	auto m = "Mary had a little lamb"s;
	for (auto p:find_all(m,'a')){
		if(*p!='a')
			cerr<<"a bug!!!\n";
	}
}
