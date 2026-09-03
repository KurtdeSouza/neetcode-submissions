class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0];
        int right;
        int output = 0;
        for(int i = 0; i < prices.size(); i++){
            right = prices[i];
            output = max(output, right - left);
            if(right < left){
                left = prices[i];
            }
        }
        return output;
    }
};
