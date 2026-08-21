class Solution {
public:
    bool box_check(vector<vector<char>>& board, int start_x, int start_y){
        set<char> row;
        for(int i = start_x; i < start_x + 3; i++){
            for(int j = start_y; j < start_y + 3; j++){
                char c = board[j][i];
                std::cout << i << "," << j << "\n";
                if(c != '.' && row.contains(c)){
                    return false;
                }else{
                    row.insert(c);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row;
        for(auto r : board){
            for(auto c: r){
                if(c != '.' && row.contains(c)){
                    std::cout << "here" << c << r[0];
                    return false;
                    
                }else{
                    row.insert(c);
                }
            }
            row.clear();

            

        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0 ; j < board[i].size(); j++){
                char c = board[j][i];
                if(c != '.' && row.contains(c)){
                    
                    return false;
                }else{
                    row.insert(c);
                }
            }
            row.clear();
        }
        for(int i = 0; i < board.size(); i += 3 ){
            for(int j = 0; j < board[i].size(); j += 3){
                if(!box_check(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};
