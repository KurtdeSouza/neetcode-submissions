class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(const auto num : nums){
            val ^= num;
        }
        return val;
    }
};
