class Solution {
public:
    int search(vector<int>& nums, int target) {
 
        int L =0 , R = nums.size() - 1;
        int M;

        while(L <= R){
            M = L + (R - L)/2;

            if(nums[M]==target ){
                return M;
            }
            //we are in left rotation and need to look right
            else if(nums[M] > nums[R]){
                if(target > nums[M]){
                    L = M + 1;
                }else{
                    if(nums[L] > target){
                        L = M + 1;
                    }else{
                        R = M - 1;
                    }
                }
            }else{
                if(target < nums[M]){
                    R = M - 1;
                }else{
                    if(nums[R] >= target){
                        L = M + 1;
                    }else{
                        R = M - 1;
                    }
                }
            }
        }
        return -1;
    }
};
