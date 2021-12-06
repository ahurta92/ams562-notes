//
// Created by adrian on 11/3/21.
//
#include <vector>
#include "examples.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
//  the one we use for the initialization in code
ostream &operator<<(ostream &os, const Entry &e) {
    return os << "{\"" << e.name << "\"," << e.number << "}";
}

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

vector<Entry> readEntries(istream &is) {
    vector<Entry> res;
    for (Entry i; is >> i;) {// read from is until somewhat that is not an integer is encountered
        res.push_back(i);
    }
    return res;
}
vector<Entry> readFileEntries(const string& f_name){
	fstream ifs;
	ifs.open(f_name);
	vector<Entry> vE;
	if (!!ifs) {
		vE = readEntries(ifs);
		ifs.close();
	} else {
		cerr << "Could not read Entries.txt" << endl;
	}
	return vE;
}

ostream &operator<<(ostream &os, const vector<Entry> &v) {
    for (const auto &i: v) os << i << "\n ";
    return os;
}
ostream& operator<<(ostream& os, const list<Entry>& lst)
{
	for (const auto &i: lst) os << i << "\n ";
	return os;
}

map<string,int> readTextMap(const string & f_name)
{
	map<string,int> my_txt;
	fstream ifs;
	ifs.open(f_name);
	int j = 0;
	if(ifs)
	{
		for(string i; ifs >> i;)
		{
			my_txt[i] = j;
			j++;
		}
	}
	else
	{
		cout << "did not read" << endl;
	}
	return my_txt;
}
istream& operator>>(istream&is,pair<string,int> &i){

	string fname;
	string lname;
	int val;
	is>>fname;
	is>>lname;
	is>>val;
	i.first=fname+" "+lname;
	i.second=val;
	return is;
}
map<string, int> readNameAgeData(const string& f_name)
{
	 map<string, int>data;;
	fstream ifs;
	ifs.open(f_name);
	int j = 0;
	if(ifs)
	{
		for(pair<string,int> i; ifs >> i;)
		{
			data[i.first] = i.second;
			j++;
		}
	}
	else
	{
		cout << "did not read" << endl;
	}
	return data;
}
