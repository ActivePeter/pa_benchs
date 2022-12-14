#include <iostream>


int main(){
    //ok
    struct Recur{
        void recur(int i){
            printf("h\n");
            if(i>0){
                recur(i-1);
            }
        }
    };
    Recur().recur(10); 
    
    //x infunc func 
    // void recur(int i){
    //     printf("h\n");
    //     if(i>0){
    //         recur(i-1);
    //     }
    // }
    // recur(i);
    
    // x //不太行
    // auto lambda=[&](int i){
    //     lambda(i-1);
    // };
    // lambda(10);
    return 0;
}