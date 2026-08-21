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
        for (auto it = h.begin(); it != h.end(); ++it) {
            if(it->second != 0){
                return false;
            }
        }
        return true;

    }
};
