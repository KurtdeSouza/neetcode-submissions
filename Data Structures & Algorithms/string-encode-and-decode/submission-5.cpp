#include <string>
#include <iostream>

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs){
            int l = s.size();
            res = res +  std::to_string(l) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
    
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = std::stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            
            res.push_back(s.substr(i,length));
            i = j;
        }
        return res;
    }
};
