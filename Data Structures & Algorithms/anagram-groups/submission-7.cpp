class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> word;
        map<vector<int>, vector<string>> res;
        for(auto s : strs){
            vector<int> word(26);
            for(auto c : s){
                word[c - 'a']++;
            }
            res[word].push_back(s);

        }
        vector<vector<string>> r;
        for (const auto& [key, value] : res) {
            r.push_back(value);
        }
        return r;
    }
};
