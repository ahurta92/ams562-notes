#include "examples.h"
//  the one we use for the initialization in code

istream &operator>>(istream &is, Entry &e) {
	// read{"name",number } pair. Note: formatted with {" ",and}
	char c, c2;
	if (is >> c && c == '{' && is >> c2 && c2 == '"') {// start with a { "
		string name;
		while (is.get(c) && c != '"')
			name += c;
		if (is >> c && c == ',') {
			int number = 0;
			if (is >> number >> c && c == '}') {// read the number and a }
				e = {name, number};//assign to the entry
				return is;
			}
		}
	}
	is.setstate(ios_base::failbit);//register the failure in the stream;
	return is;
}
vector<Entry> read_entries(istream& is)
{
	vector<Entry> res;
	for(Entry i; is>>i;)
		res.push_back(i);
	return res;
}

istream& operator>>(istream& is, vector<Entry>& v)
{
	for(Entry i; is>>i;)
		v.push_back(i);
	return is;
}
