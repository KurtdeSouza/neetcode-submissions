class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = heights.size() - 1;
        int res = 0;
        int left, right;
        int curr;
        while(L < R){
            left = heights[L];
            right = heights[R];
            curr = min(left , right) * (R - L );
            if(curr > res){
                res = curr;
            }
            if(left < right){
                L++;
            }else if(right < left){
                R--;
            }else{
                L++;
                R--;
            }

        }
        return res;
    }
};
