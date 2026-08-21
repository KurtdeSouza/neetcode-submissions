class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists(nums.begin(), nums.end());
        int count = 1;

        int check;
        int i;
        if(nums.size() == 0){
            return 0;
        }
        for(const auto& n : nums){
            if(!exists.contains(n - 1)){
                i = 1;
                check = 1;
                while(exists.contains(n + i)){
                    check++;
                    i++;
                }
                if(check > count){
                    count = check;
                }
            }
        }
        return count;
    }
};
