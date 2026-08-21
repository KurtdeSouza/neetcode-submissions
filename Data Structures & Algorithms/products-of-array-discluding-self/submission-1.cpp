class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //assume 1 on either side of nums
        // mul prev nums * res prev = store in current res
        int RHS = 1, LHS = 1;
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                res[i] = 1;
            }else{
                res[i] = res[i-1] * nums[i-1];
            }
        }
        for(int i = nums.size() - 1; i > -1; i--){
            if(i == nums.size() - 1){
                RHS = nums[i];
            }else{
                res[i] = RHS * res[i];
                RHS *= nums[i];
            }
        }
        return res;
        //on the way back (RHS => LHS)
        //running total * current res = store in curernt res
        //running total * current nums = running total

    }
};
