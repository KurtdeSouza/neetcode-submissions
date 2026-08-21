class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        int M;
        // 0, 2, 5
        // 2, 3, 5
        // 2, 2, 3
        if(nums[L] == target){
            return L;
        }
        if(nums[R] == target){
            return R;
        }
        while(L + 1 < R){
            M = L + (R - L)/2;
            if(nums[M] == target){
                return M;
            }
            else if(M > target){
                R = M;
            }else{
                L = M;
            }
        }
        return  -1;

    }
};
