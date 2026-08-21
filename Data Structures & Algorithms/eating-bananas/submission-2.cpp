class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int R = 0, L=1 , k;
        for(int i = 0; i < piles.size(); i++){
            R = max(R, piles[i]);
        }
        //  L = 1, R = 4;
        int temp_h = 0;
        pair<int, int> best = {10000000001, 0};
        while(L <= R){
            //k = 2
            // 1 + 2 + 2 + 1
            // 6
            k = L + (R - L)/2;
            temp_h = 0;
            for(auto p : piles){
                if (p > k){
                    if(p % k > 0){
                        temp_h +=1 + p/k;
                    }else{
                        temp_h += p/k;
                    }
                }else{
                    temp_h += 1;
                }
            }
            if(h - temp_h < best.first && h - temp_h >= 0){
                best = {h - temp_h, k};

            }else if(h - temp_h == best.first && k < best.second){
                best = {h - temp_h, k};

            }
            if(temp_h <= h){
                
                R = k - 1;
            }else{
                L = k + 1;
            }
        }
        return best.second;
    }
};
