#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_2_idx;
        for(int i=0;i<nums.size();i++){
            value_2_idx[nums[i]]=i;
        }
        for(auto v:nums){
            auto find=value_2_idx.find(target-v);
            if(find!=value_2_idx.end() ){
                std::vector<int> ret;
                ret.push_back(v);
                ret.push_back(find->second);
                return ret;
            }
        }
        return {};
    }
};