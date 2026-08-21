class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); i++){
            int search = target - nums[i];
            if (h.contains(search)){
                return {h[search], i};
            }else{
                h[nums[i]] = i;
            }
        }
        return {};
    }
};
