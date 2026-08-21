class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists;
        exists.reserve(nums.size());
        int count = 1;
        for(const auto& n : nums){
            exists.insert(n);
        }
        int check;
        int i;
        if(nums.size() == 0){
            return 0;
        }
        for(const auto& n : nums){
            if(!exists.contains(n - 1)){
                i = 1;
                check = 1;
                exists.erase(n);
                while(exists.contains(n + i)){
                    check++;
                    exists.erase(n + i);
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
