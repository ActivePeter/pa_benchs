#include "list"
#include "unordered_map"
#include <vector>
using namespace std;


class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int begin=0;
        int max_=0;
        // int ccnt[256]={0};//下标
        vector<int> ccnt(256,-1);//记录
        for (int i = 0; i < s.size(); i++)
        {   
            if(ccnt[s[i]]==-1){
                
            }else if(ccnt[s[i]]>=begin){
                // for(int z=begin;z<i;z++){

                // }

                begin=ccnt[s[i]]+1;
            }
            ccnt[s[i]]=i;
            max_=max(max_,i-begin+1);
            /* code */
        }
        return max_;
    }
};

int main(){
    Solution().lengthOfLongestSubstring("abcabcbb");
    return 0;
}