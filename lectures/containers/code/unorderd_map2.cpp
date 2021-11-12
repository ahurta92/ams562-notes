#include "examples.h"
#include <unordered_map>

struct Record{
	string name;
	int product_code;
	//...
};

struct Rhash{
	size_t operator()(const Record&r)const
	{
		return hash<string>()(r.name)^hash<int>()(r.product_code);
	}
};

int main()
{
	vector<Record> v;
	Record one={"A",2};
	v.push_back({"A",2});
	v.push_back(one);

	v.emplace_back(Record{"A",2});
}
