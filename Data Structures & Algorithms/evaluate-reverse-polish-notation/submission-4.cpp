class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        int sum = 0;
        int temp1,temp2;
        for(const string& t : tokens){
            if(t == "+" || t == "-" ||t == "*" || t == "/" ){

                temp1 = res.top();
                res.pop();
                temp2 = res.top();
                res.pop();
                if(t == "+") res.push(temp1 + temp2);
                else if(t == "-") res.push(temp2 - temp1);
                else if(t == "*") res.push(temp1 * temp2);
                else res.push(temp2 / temp1);
            }else{
                res.push(stoi(t));
            }
        }
        return res.top();
    }
};
