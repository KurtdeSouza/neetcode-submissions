class Solution {
public:
    bool containsNum(set<int> s, int num){
        if(s.find(num) == s.end()){
            return false;
        }
        return true;
    }
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }
        }
        int res = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(containsNum(s, nums[i]) && !containsNum(s, nums[i] - 1)){
                curr = 0;
                int num = nums[i];
                while(containsNum(s, num)){
                    curr++;
                    s.erase(num);
                    num++;
                }
                if(curr > res){
                    res = curr;
                }
            }
        }
        return res;

    }
};
