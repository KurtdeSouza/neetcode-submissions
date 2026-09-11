class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word, int word_index, set<pair<int,int>>& visited, pair<int,int> curr){
        /*
        add cell to visited
        iterate over neighboring cells checking for the words next char


        */
        if(word_index == word.size()){
            return true;
        }
        visited.insert({curr});
        int row_size = board.size();
        int col_size = board[0].size();
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};

        for(const auto d : directions){
            int ni = curr.first + d.first;
            int nj = curr.second + d.second;
            if(ni >= 0 && ni < row_size
            && nj >= 0 && nj < col_size
            && board[ni][nj] == word[word_index]
            &&!visited.contains({ni,nj})){
                if(dfs(board, word, word_index + 1, visited, {ni, nj})){
                    return true;
                }else{
                    visited.erase({ni,nj});
                }
            }
        }
        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> visited;
        for(int i =0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(!visited.contains({i,j}) && board[i][j] == word[0]){
                    if(dfs(board, word,1, visited,{i,j})){
                        return true;
                    }
                    visited.clear();
                }
            }
        }
        return false;


    }
};
