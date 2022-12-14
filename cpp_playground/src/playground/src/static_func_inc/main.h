#include "classB.h"
#include "classA.h"
int main(){
    A a;
    B b;
    // a.useB(&b);
    // b.useA(&a);
    a.func();

    return  0;
}