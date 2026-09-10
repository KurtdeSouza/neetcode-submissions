class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_true = 0;
        for(int i =0; i < nums.size(); i++){
            if(i <= last_true){
                last_true = max(last_true, i + nums[i]);
            }
        }
        
        return last_true >= nums.size() - 1;
    }
};
