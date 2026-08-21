class Solution {
public:
    int findMin(vector<int> &nums) {
        int L =0 , R = nums.size() - 1;
        int M;
        if(nums.size() == 1){
            return nums[0];
        }
        while(L <= R){
            M = L + (R - L)/2;
            if(M == 0){
                return min(nums[0], nums[1]);
            }
            if(nums[M] < nums[M - 1] ){
                return nums[M];
            }
            //we are in left rotation and need to look right
            else if(nums[M] > nums[R]){
                L = M + 1;
            }else{
                R = M - 1;
            }
        }
        return nums[M];
    }
};
