//
// Created by adrian on 11/4/21.
//
#include "examples.h"
ostream &operator<<(ostream &os, const complex &c) {
    os<< c.real()<<"+ "<<c.imag()<<"i";
    return os;
}