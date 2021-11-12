#include "examples.h"
#include "VectorRangeCheck.h"


void no_range_check(Vec<int>& a){
	int i=a[a.size()];
	cout<<i<<endl;///???????????
}

int main() {


	try{

		Vec<int> a={1,2,3,4,5};
		no_range_check(a);

	}
	catch(out_of_range&){
		cerr<<"range error\n";
	}
	catch(...){
		cerr<<"unknown exception thrown\n";
	}

}

