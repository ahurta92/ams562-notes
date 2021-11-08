//
// Created by adrian on 11/6/21.
//
#include <list>
#include "examples.h"

int get_number(const string& s, const list<Entry>& phone_book)
{
	for(auto p=phone_book.begin();p!=phone_book.end();++p)
		if(p->name == s)
			return p->number;
	return 0; // number not found
}

int main()
{
	list<Entry> contacts = {
		{"Adrian Hurtado", 1234567}, {"Stella Salina", 1223442}, {"Johnny Z", 2323232}};
	int num = get_number("Adrian Hurtado", contacts);
	cout<<"my number: "<<num;
}
