#include <tuple>

auto gettuple()->struct{
    int a;
    int b;
} {
    return std::make_tuple(1,nullptr);
}

int main(){
    auto [a,b]=gettuple();

    return 1;
}