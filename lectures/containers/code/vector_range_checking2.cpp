#include "examples.h"
#include "VectorRangeCheck.h"


void no_range_check(Vec<int>& a){
	int i=a[a.size()];
	cout<<i<<endl;///???????????
}

int main() {

    Vec<int> a={1,2,3,4,5};
//	no_range_check(a);

	for(std::vector<int>::reverse_iterator itr=a.rbegin();itr!=a.rend();itr++)
		cout<<*itr<<std::endl;

}

