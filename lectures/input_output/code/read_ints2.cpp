#include "examples.h"

vector <int> read_ints(istream &is,const string&terminator){
	vector<int> res;
	for(int i; is>>i;)
		res.push_back(i);

	if(is.eof())
		return res;
	if (is.fail()){// we failed to read an int; was it the terminator?
		is.clear(); // reset the state to good()
		is.unget(); // put the non-digit back into the stream
		string s;
		if(cin>>s&&s==terminator){// if its a string and the string is the terminator
			return res;
		}
		cin.setstate(ios_base::failbit);// add fail() to cin's state
	}
	return res;
}