//
// Created by adrian on 11/4/21.
//

#ifndef LECTURE_EXAMPLES_H
#define LECTURE_EXAMPLES_H
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>


using namespace std;

struct Entry{
	string name;
	int number;
};
	//  the one we use for the initialization in code
ostream &operator<<(ostream &os, const Entry &e);

ostream &operator<<(ostream &os, const vector<Entry> &v);
istream &operator>>(istream &is, Entry &e);
ostream &operator<<(ostream &os, const list<Entry> &lst);

template <typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
	for (auto&e:v){
		os<<e<<" ";
	}
	os<<"\n";
	return os;
}

vector<Entry> readEntries(istream &is);
vector<Entry> readFileEntries(const string& f_name);
map<string,int> readTextMap(const string & f_name);
map<string,int> readNameAgeData(const string & f_name);





#endif //LECTURE_EXAMPLES_H
