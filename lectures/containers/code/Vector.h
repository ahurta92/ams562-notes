//
// Created by adrian on 11/4/21.
//

#ifndef LECTURE_VECTOR_H
#define LECTURE_VECTOR_H

template<typename T>
class Vector {
    T *elem;// pointer to first element
    T *space; //pointer to first unused (and uninitialized) slot
    T *last;// pointer to last slot
public:
    //...
    int size(); // number of elements (space-elem)
    int capacity(); //number of slots available for elements (last-elem)
    //...
    void reserve(int newsz); // increase capacity() to newsz
    //...
    void push_back(const T &t); //copy t into Vector
    void push_back(T &&t); // move t into Vector
};




#endif //LECTURE_VECTOR_H
