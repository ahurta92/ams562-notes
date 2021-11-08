#include "examples.h"

template <typename T>
void print_vector(std::vector<T> v){
    for(int i=0;i!=v.size();++i)
        cout<<v[i]<<" ";
    cout<<"\n";
}
class X{};

int main() {
    print_vector<int>({1,2,3,4,5});
    print_vector<double>({1.0,2.2,3,4.0004,5});
    print_vector<complex>({{1,2},{3.0,5.0},{2.0,2.0}});

}

