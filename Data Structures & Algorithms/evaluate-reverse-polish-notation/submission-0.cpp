class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        int sum = 0;
        int temp1,temp2;
        for(string t : tokens){
            if(t == "+"){
                temp1 = res.top();
                res.pop();
                temp2 = res.top();
                res.pop();
                res.push(temp1 + temp2);
            }else if(t == "-"){
                temp1 = res.top();
                res.pop();
                temp2 = res.top();
                res.pop();
                res.push(temp2 - temp1);
            }else if(t == "*"){
                temp1 = res.top();
                res.pop();
                temp2 = res.top();
                res.pop();
                res.push(temp1 * temp2);
            }else if(t == "/"){
                temp1 = res.top();
                res.pop();
                temp2 = res.top();
                res.pop();
                res.push(temp2 / temp1);
            }else{
                res.push(stoi(t));
            }
        }
        return res.top();
    }
};
