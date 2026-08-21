#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> h;
        for(char c : s){
            h[c]++;
        }
        for(char c : t){
            h[c]--;

        }
        for (auto i : h){
            if(i.second != 0){
                return false;
            }
        }
        return true;

    }
};
