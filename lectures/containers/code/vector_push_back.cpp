#include "examples.h"
// reads ints from a text

int main() {

    fstream ifs;// file stream
    ifs.open("ints.txt");//open file
    std::vector<int> a;
    if(ifs){// if file open
        for(int e;ifs>>e;)// reads until something other int is encountered
            a.push_back(e);// push back
        ifs.close();
    }else{
        cout<<"did not open ints.txt"<<endl;
    }
    cout<<"a.size() "<<a.size()<<std::endl;
    for(auto& e:a)
        cout<<e <<" ";
    cout<<"\n";



}

