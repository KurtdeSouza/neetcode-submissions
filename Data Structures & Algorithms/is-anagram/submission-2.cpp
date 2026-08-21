class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> res(26);
        for(auto i: s){
            res[i - 'a']++;
        }
        for(auto i : t){
            res[i-'a']--;
        }
        for(auto i : res){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
};
