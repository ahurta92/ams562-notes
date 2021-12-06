#include "iostream"
using namespace std;

int *getArray(int s) {
  //int a[s]; // local variable
 // int* ptra=a;
  int *a = new int[s];
  int *b = new int[s];
  for (int i = 0; i < s; i++) {
    a[i] = i;
    std::cout << &*(a+i) << std::endl;
  }
  delete[] b;
  return a;
}

int main() {
  int size = 6;
  int *ptr = nullptr;
  ptr = getArray(size);
	cout<<"main"<<endl;

  for (int i = 0; i < size; i++) {
    std::cout << ptr[i] << std::endl;
  }
  delete[] ptr;
}
