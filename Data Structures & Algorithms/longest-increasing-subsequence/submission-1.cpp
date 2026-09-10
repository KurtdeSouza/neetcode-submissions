class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& result, int curr){
        if(result[curr] != -1){
            return result[curr]; //we've done the work to find this answer dnr
        }
        for(int i  = curr - 1; i > -1; i--){
            if(nums[i] < nums[curr]){
                result[curr] = max(result[curr], 1 + dfs(nums, result, i)); //either include i element or don't
            }
        }
        if(result[curr] == -1){
            result[curr] = 1; //base case is 1 but we cannot return -1
        }
        return result[curr];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        for(int i = nums.size() - 1; i > -1; i--){
            dfs(nums, result, i);
        }
        return ranges::max(result);
    }
};
