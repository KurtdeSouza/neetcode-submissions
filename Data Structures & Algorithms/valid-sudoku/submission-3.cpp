class Solution {
public:
    bool checkCol(vector<vector<char>>& board, int col){
        set<char> st;
        for(int i = 0; i < board.size(); i++){
            if(board[i][col] != '.'){
                if(st.find(board[i][col]) == st.end()){
                    st.insert(board[i][col]);
                }else{
                    cout << col << "Col";
                    return false;
                }
            }
        }
        return true;
    }

    bool checkRow(vector<vector<char>>& board, int row){
        set<char> st;
        for(int j = 0; j < board.size(); j++){
            if(board[row][j] != '.'){
                if(st.find(board[row][j]) == st.end()){
                    st.insert(board[row][j]);
                }else{
                    cout << row << "Row";
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board, int box){
        int i_start = (box / 3) * 3;  // Find the row start index
        int j_start = (box % 3) * 3;  // Find the column start index
        set<char> st;
        for (int i = i_start; i < i_start + 3; i++) {
            for (int j = j_start; j < j_start + 3; j++) {
                cout << j << "\n";
                cout << i << "\n";
                if(board[i][j] != '.'){
                    if(st.find(board[i][j]) == st.end()){
                        st.insert(board[i][j]);
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    bool checkCols(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            if(checkCol(board, i) == false){
                return false;
            }
        }
        return true;
    }
    bool checkRows(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            if(checkRow(board, i) == false){
                return false;
            }
        }
        return true;
    }
    bool checkBoxes(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
           if(checkBox(board, i) == false){
                return false;
            } 
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board){
        if(checkRows(board)  && checkCols(board) && checkBoxes(board)){
            return true;
        };
        return false;
    }
    
};