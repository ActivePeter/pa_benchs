#include <iostream>

int main(){
    int a=1,b=2;
    int *a_=&a;
    int*b_=&b;
    (false?*a_:*b_)++;
    (true?*a_:*b_)++;
    return 1;
}