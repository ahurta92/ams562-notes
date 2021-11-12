#include "examples.h"

void no_range_check(vector<int>& a){
	int i=a[a.size()];
	cout<<i<<endl;///???????????
}

int main() {

    std::vector<int> a={1,2,3,4,5};
	no_range_check(a)
}

