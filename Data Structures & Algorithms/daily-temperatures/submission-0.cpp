class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> res;
        vector<int> result(temperatures.size(), 0);
        int curr, index;
        for(int i = 0; i < temperatures.size(); i++){
            curr = temperatures.at(i);
            while(res.size() != 0 && temperatures.at(res.top()) < curr ){
                index = res.top();
                res.pop();
                result[index] = i - index;
            }
            res.push(i);
        }
        return result;
    }
};
