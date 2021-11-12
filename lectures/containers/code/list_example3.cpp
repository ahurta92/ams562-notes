//
// Created by adrian on 11/6/21.
//
#include <list>
#include "examples.h"

void f(const Entry&ee,list<Entry>& phone_book, list<Entry>::iterator p,list<Entry>::iterator q){
	phone_book.insert(p,ee);
	phone_book.erase(q);
}

int main()
{
	list<Entry> contacts = {
		{"Adrian Hurtado", 1234567}, {"Stella Salina", 1223442}, {"Johnny Z", 2323232}};

	f({"Brian ",123212},contacts,contacts.begin(),--contacts.end());
	auto fp=contacts.begin();
	auto ep=--contacts.end();
	cout<<"The first contact: \n"<<fp->name<<": "<<fp->number<<"\n";
	cout<<"The last contact: \n"<<ep->name<<": "<<ep->number<<"\n";
}
