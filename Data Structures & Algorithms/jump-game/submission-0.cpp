class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> result(nums.size(), false);
        result[0] = true;
        for(int i = 0 ; i < nums.size(); i++){
           
            if(result[i] == true){
                for(int j = 0; j <=  nums[i]; j++){
                    int index = i + j;
                    if(index < nums.size())  {
                        result[index] = true;
                    }
                }
            }
            
        }
        return result[nums.size() -1];
    }
};
