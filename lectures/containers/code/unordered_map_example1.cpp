#include "examples.h"
#include <unordered_map>

ostream& operator<<(ostream &os,un<string,int> m){
	for(const auto& e:m)// again we can iterate using range for
		os<<e.first<<" "<<e.second<<endl;
	// first and second to access key and value pair
}

int get_number(const string&s,map<string,int>& phone_book){
	return phone_book[s];
}

int main()
{
	unordered_map<string,int> contacts = {
		{"Adrian Hurtado", 1234567}, {"Stella Salinas", 1223442}, {"Johnny Z", 2323232}};
	int my_puppies_number=get_number("Stella Salinas",contacts);
	cout<<contacts;
	int new_number=get_number("BrOOOO",contacts);// notice that BrOOOO is entered into the map
	cout<<"After first get number call"<<std::endl;
	cout<<contacts;
}
