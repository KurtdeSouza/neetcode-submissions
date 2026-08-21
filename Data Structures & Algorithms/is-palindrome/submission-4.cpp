class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.size() - 1;
        while(L < R){
            
            if(isalnum(s[L])){
                if(isalnum(s[R])){
                    if(tolower(s[L]) == tolower(s[R])){
                        L++;
                        R--;
                    }else{
                        return false;
                    }
                }else{
                    R--;
                }
            }else{
                L++;
            }
        }
        return true;
    }
};
