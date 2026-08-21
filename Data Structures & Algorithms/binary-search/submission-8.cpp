class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        int M;
        // 0, 2, 5
        // 2, 3, 5
        // 2, 2, 3
        
        while(L <= R){
            M = L + (R - L)/2;
            if(nums[M] == target){
                return M;
            }
            else if(nums[M] > target){
                R = M - 1;
            }else{
                L = M + 1;
            }
        }
        return  -1;

    }
};
