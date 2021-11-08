#include "examples.h"
#include <unordered_map>

struct Record{
	string name;
	int product_code;
	//...
};

struct Rhash{
	size_t operator()(const Record&)const
	{
		return hash<string>()(r.name)^hash<int>()(r.product_code);
	}
};

int main()
{
	unordered_set<Record,Rhash> my_set;// set of re
}
