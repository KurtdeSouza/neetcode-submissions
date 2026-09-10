class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*

            b   b   m
        m
        b   1    1   0
        a   4    4   3  2   2 
        b   3    3   3  2   2
        t   2    2   2  2   1
        b   2    2   2  1   1
        t   1    1   1  1   0
        1. build dp cache => vector<vector<int>> => row = text1 +1 col = text2 + 1
        2. iterate over grid bottom up starting from last char in each
            2.1 if text[i] == text[j] => max(1 + i+1, j+1, right/down row)
            2.2 else take max of (i,j+1) (i+1, j) (i +1, j+1)
       
        3. once iteration finishes return dp_cacge[0][0]

        */
        vector<int> dp_cache(text1.size()+1, 0);
        vector<int> prev_dp_cache(text1.size() + 1, 0);
        int match_adj;
        for(int j = text2.size() -1; j > -1; j--){ //iterate over text2 backward to check char match
            char t2_curr = text2[j];
            for(int i = text1.size() - 1; i > -1; i--){
                char t1_curr = text1[i];
                if(t1_curr == t2_curr){
                    dp_cache[i] = max({prev_dp_cache[i+1] + 1, dp_cache[i+1], prev_dp_cache[i]});
                }
                else{
                    dp_cache[i] = max({prev_dp_cache[i+1], dp_cache[i+1], prev_dp_cache[i]});

                }
            }
            prev_dp_cache = dp_cache;
        }
        return dp_cache[0];
    }

    
};
