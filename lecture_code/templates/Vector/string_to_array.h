#include <iostream>
#include <string>
#include "VectorT.h"

#include <vector>

Vector<std::string> string_to_array(const std::string& s)
{

	Vector<std::string> words;
	size_t found = 0;
	size_t first = 0;
	// find_first_of returns std::string::npos if char is not found
	while(found != std::string::npos)
	{
		first = found;
		found = s.find_first_of(' ', found);

		if(found != std::string::npos)
		{
			std::string word = s.substr(first, found - first);
			words.push_back(word);
			found++;
		}
		else
		{
			std::string word = s.substr(first);
			words.push_back(word);
		}
		// get the last
	}
	return words;
}

void write(const Vector<std::string>& vs)
{
	for(int i = 0; i != vs.size(); ++i)
		std::cout << vs[i] << "\n";
}
