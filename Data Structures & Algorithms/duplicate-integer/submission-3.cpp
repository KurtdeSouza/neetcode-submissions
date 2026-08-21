#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hashMap;
        for (int num : nums){
            if(hashMap.find(num) != hashMap.end()){
                return true;
            }else{
                hashMap[num] = 1;
            }
        }
        return false;
    }
};
