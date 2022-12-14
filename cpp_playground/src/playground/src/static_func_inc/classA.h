#pragma once
#include <iostream>

#include "classB.h"
// struct B;
struct A
{
    // void useB(B* b);
    void func(){
        B::func();
    }
};

