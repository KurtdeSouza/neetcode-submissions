class Solution {
public:
    int climbStairs(int n) {
        if( n <= 2){
            return n;
        }
        vector<int> possible(n, 0);
        possible[0] = 1;
        possible[1] = 2;
        for(int i = 2; i < n; i++){
            possible[i]+= possible[i-1] + possible[i-2];
        }
        return possible[n-1];
    }
};
