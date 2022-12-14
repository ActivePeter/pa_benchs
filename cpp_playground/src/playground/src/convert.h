#include <iostream>
#include <algorithm>
struct NumberFromStr{
    // AttrType float_or_int=AttrType::INTS;
    int state=0;//0 整数 1小数
    float float_=0;
    int int_=0;
    NumberFromStr(const char* str){
        
        char* c=(char*)str;
        int float_jw=10;
        while(*c){
            if  (*c>='0'&& *c<='9'){
                if(state==0){
                    int_*=10;
                    int_+=*c-'0';
                }else{
                    float_+=1.0*(*c-'0')/float_jw;
                    float_jw*=10;
                }
            }else if(*c=='.'){
                state=1;
                float_=int_;
            }else{
                break;
            }
            c++;
        }
        // float_or_int=state==0?AttrType::INTS:AttrType::FLOATS;
    }
};
bool is_same_str_lower(const char* a,const char* b)
    {
        std::string aa(a);
        std::string bb(b);
        std::transform(aa.begin(),aa.end(),aa.begin(),::tolower);
      std::transform(bb.begin(),bb.end(),bb.begin(),::tolower);
      return aa==bb;
    }
int main(){
    // const char* a="1.222";
    // NumberFromStr aa("1.222sss");
    // NumberFromStr bb("1");
    // NumberFromStr cc("1.222");
    // NumberFromStr dd("1sss");
    // NumberFromStr ee("sss");
    auto v=is_same_str_lower("ahb","AhB");
    // char buf[100];
    // sprintf(buf,"%g",1);
    // printf("%s\n")
    
    return 1;
}