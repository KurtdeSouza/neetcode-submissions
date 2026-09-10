class Solution {
public:

    int minDistance(string word1, string word2) {
        int i = 0;
        vector<vector<int>> result(word1.size()+1, vector<int>(word2.size()+1,INT_MAX));
        
        for(int i = 0; i < word1.size() + 1; i++){
            result[i][word2.size()] = word1.size() - i;
        }
        
        for(i = 0; i < word2.size() + 1; i++){
            result[word1.size()][i] = word2.size() - i;
        }
        
        for(int i = word1.size() - 1; i > -1; i--){
            for(int j = word2.size() - 1; j > -1; j--){
                if(word1[i] == word2[j]){
                    result[i][j] = result[i+ 1][j+1];
                }else{
                    result[i][j] = 1 + min({result[i][j+1], result[i+1][j], result[i+1][j+1]});
                }
            }
        }
        
        return result[0][0];
        
        //get sum of result array
        

    }
};
