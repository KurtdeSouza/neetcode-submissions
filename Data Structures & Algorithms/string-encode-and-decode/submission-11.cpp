#include <cctype> 
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for(auto s : strs){
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> decoded;
        int i = 0;
        while(i < s.size()){
            int pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            i = pos + 1;
            decoded.push_back(s.substr(i, len));
            i += len;
        }
        return decoded;
    }
};
