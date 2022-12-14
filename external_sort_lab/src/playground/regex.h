#include <iostream>
#include <regex>

// using namespace std;

bool like(const char* a,const char* b){
    char* c=(char*)a;
    std::string re="";
    while(*c){
        if(*c=='%'){
            re+="[^']*";
        }else if(*c=='_'){
            re+="[^']";
        }else{
            re+="[";
            re+=*c;
            re+="]";
        }
        c++;
    }
    std::regex rule(re);
    return std::regex_match(b, rule);
}

int main() {
    using namespace std;
	cout << like("_m%","hmmmm") << endl;    //1
	cout << like("_m%","hhmmm") << endl;    //ok
	cout << like("_m_","hmmmm") << endl;    //1

	return 0;
}
