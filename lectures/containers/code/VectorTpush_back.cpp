#include "Vector.h"

template<typename T>
void Vector<T>::push_back(const T &t) {
    if(capacity()<size()+1)// make sure we have enough space
        reserve(size()==0?8:2*size());//double the capacity

    new(space) T{};
    ++space;
}

