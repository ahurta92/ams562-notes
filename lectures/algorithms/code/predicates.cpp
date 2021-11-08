#include "examples.h"

struct Greater_than
{
	int val;
	explicit Greater_than(int v)
		: val{v}
	{}
	bool operator()(const pair<string, int>& r) const
	{
		return r.second > val;
	}
};

int main()
{
	map<string, int> data = readNameAgeData("name_age.csv");
	for(auto& e : data)
	{
		cout << "Name: " << e.first << ", age: " << e.second << endl;
	}
	int num = 25;
	auto p = find_if(data.begin(), data.end(), Greater_than{num});
	cout<<endl;
	cout << "First greater than " << num << " : " << endl;
	cout << "Name: " << p->first << ", age: " << p->second << endl;
	string name1=p->first;
	int num1=p->second;

	auto q = find_if(data.begin(), data.end(),[&num1,&name1](const auto& r){ return r.first==name1&&r.second==num1;});
	cout << "Find the same element" << num << " : " << endl;
	cout << "Name: " << q->first << ", age: " << q->second << endl;

}
