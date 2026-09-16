class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int L = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(char_map.contains(s[i])){
                count = max(count, i - L);
                L = max(char_map[s[i]] + 1, L);
            }
            char_map[s[i]] = i;
            
        }
        if(L != s.size() - 1 || s.size() == 1){
            count = max(count, (int)s.size() - L);
        }
        return count;
    }
};
