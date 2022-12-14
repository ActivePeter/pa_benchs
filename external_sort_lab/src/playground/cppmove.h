#include <iostream>
#include <functional>
using namespace std;
struct PageBorrower{
    int pid;
};
int cnt=0;
template <typename N>
struct Unique{
    bool alive=true;
    int a;
    char data[sizeof N];
    function<void(N&)> on_destruct=nullptr;
    N& ref(){
        return *((N*)data);
    }
    N&& move(){
        return std::move(*this);
    }
    //拷贝构造
    Unique<N>& operator=(Unique<N> const& up) = delete;
    Unique(Unique &&d){
        cout<<"move construct!"<<endl;
        d.alive=false;
        ref()=d.ref();
        on_destruct=d.on_destruct;
        a=cnt++;
    }
    Unique(N v_,function<void(N&)> on_destruct_){
        ref()=v_;
        a=cnt++;
        on_destruct=on_destruct_;
    }
    ~Unique(){
        if(alive){
            cout<<"destruct!"<<a<<endl;
            if(on_destruct){
                on_destruct(ref());
            }
        }
    }
};

int main(){
    Unique<PageBorrower> unique=Unique<PageBorrower>(PageBorrower{33},[](PageBorrower& bo){
        printf("unpin %d\n",bo.pid);
    });
    Unique<PageBorrower> unique2=std::move(unique);
    printf("bf end\n");
    return 0;
}