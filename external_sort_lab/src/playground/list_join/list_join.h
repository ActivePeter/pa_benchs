#include <iostream>
#include <list>

int main(){
    std::list<int> l;
    l.push_back(1);l.push_back(2);
    std::list<int> l2;
    l2.push_back(3);
    
    //l pop to l2 front
    auto llastiter=l.end();
    llastiter--;
    l2.splice(l2.begin(),l,llastiter,l.end());

    return 0;
}