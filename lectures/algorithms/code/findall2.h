//
// Created by adrian on 11/8/21.
//
#ifndef LECTURE_FINDALL2_H
#define LECTURE_FINDALL2_H
template <typename T>
using Iterator=typename T::iterator;

template<typename C,typename V>
vector<Iterator<C>> find_all(C& c, V v)
{
	vector<Iterator<C>> res;
	for(auto p = c.begin(); p != c.end(); ++p)
	{
		if(*p==v){
			res.push_back(p);
		}
	}
	return res;
}
#endif //LECTURE_FINDALL2_H
