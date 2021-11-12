#include "examples.h"
#include <map>
#include <algorithm>

ostream& operator<<(ostream &os,map<string,int> m){
	for(const auto& e:m)// again we can iterate using range for
		os<<e.first<<" "<<e.second<<endl;
	// first and second to access key and value pair
}

int get_number(const string&s,map<string,int>& phone_book){
	auto p= phone_book.find(s);
	if (p==phone_book.end()){
		cout<<"We did not find our number!!!!!"<<endl;
	}
	return p->second;// i return p->second
}
// Here we are using find and instert
// find returns and iterator to the element if it is found
// returns the last iterator if not found
template<typename T,typename P>
struct my_pair{
	T first;
	P second;
};

int main()
{
	map<string,int> contacts = {
		{"Adrian Hurtado", 1234567}, {"Stella Salinas", 1223442}, {"Johnny Z", 2323232}};
	int my_puppies_number=get_number("Stella Salinas",contacts);
	cout<<contacts;
	int new_number=get_number("BrOOOO",contacts);// notice that BrOOOO is entered into the map
	cout<<"After first get number call"<<std::endl;
	cout<<contacts;
	contacts.insert(std::pair<string,int>("yo",1231223));
	std::pair<string,int>p1{"hello",42};
	my_pair<string,int> p2{"hello",42};

	p2.first;
	p2.second;

	cout<<"After insert "<<std::endl;

	cout<<contacts;
	// here we insert a pair of values
}
