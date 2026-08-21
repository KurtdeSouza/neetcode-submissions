class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
 
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int L = i + 1, R = nums.size() - 1;

            while(L < R){
                int sum;
                sum = nums[i] + nums[L] + nums[R];
                if(sum < 0){
                    L++;
                }else if(sum > 0){
                    R--;
                }else{

                    res.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while(L < R &&  nums[L] == nums[L - 1]){
                        L++;
                    }
                }
            }
        }
        return res;
    }
};
