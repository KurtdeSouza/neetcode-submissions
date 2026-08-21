class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0, R = matrix.size() - 1, M;
        while(L <= R){
            M = L + (R - L)/2;
            if(matrix[M][0] <= target && matrix[M][matrix[M].size()-1] >= target){
                break;
            }else if(matrix[M][0] > target){
                R = M - 1;
            }else{
                L = M + 1;
            }
        }
        // M = correct row
        L = 0;
        R = matrix[M].size() - 1;
        int MR;
        while( L <= R){
            MR = L + ( R - L)/2;
            if(matrix[M][MR] == target){
                return true;
            }else if( matrix[M][MR] > target){
                R = MR - 1;
            }else{
                L = MR + 1;
            }
        }
        return false;
    }
};
