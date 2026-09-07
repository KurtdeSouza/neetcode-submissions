class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> result(amount + 1, -1);
        result[0] = 0;
        for(int i = 0; i < amount + 1; i++){
            if(result[i] == -1){
                continue;
            }
            for(const auto & coin : coins){
                if(coin >amount){
                    continue;
                }
                if(i + coin <= amount){

                    if(result[i + coin] == -1){
                        result[i+coin] = result[i] + 1;
                    }else{
                        result[i+coin] = min(result[i+coin], result[i] + 1);
                    }
                }
            }
        }
        return result[amount];
    }
};
