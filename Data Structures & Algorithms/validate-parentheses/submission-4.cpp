class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == ')'){
                if(st.size() > 0 && st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            }
            else if(c == ']'){
                if(st.size() > 0 && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }
            else if(c == '}'){
                if(st.size() > 0 && st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }
            if(c == '[' || c == '(' || c == '{'){
                st.push(c);

            }
        }
        return st.size() == 0;
    }
};
