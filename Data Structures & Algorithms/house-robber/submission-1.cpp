class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> result = (nums);
        result[1] = max(result[0], result[1]);
        int res = 0;
        for(int i = 2 ; i < result.size(); i ++){
            result[i] = max(result[i-1], result[i - 2] + result[i]);
            res = max(res, result[i]);
            
        }
        return res;
    }
};
