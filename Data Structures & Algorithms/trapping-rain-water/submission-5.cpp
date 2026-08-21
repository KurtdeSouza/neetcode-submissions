class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0,L = 0, R = height.size() - 1;
        int Lmax = 0, Rmax = 0;
        while(L <= R){
            if(Lmax <= Rmax){
                res += Lmax - min(Lmax,height[L]);
                if(Lmax < height[L]){
                    Lmax = height[L];
                }
                L++;

            }else{
                res += Rmax - min(Rmax, height[R]);
                if(Rmax < height[R]){
                    Rmax = height[R];
                }
                R--;
            }
        }
        return res;

    }
};
