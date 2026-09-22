class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> t(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(t[board[i][j] - '0'] == 0) t[board[i][j] - '0']++;
                    else return 0;
                }
            }
        }
        
        for(int i = 0; i < 9; i++){
            vector<int> t(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(t[board[j][i] - '0'] == 0) t[board[j][i] - '0']++;
                    else return 0;
                }
            }
        }
        
        
        for(int blockRow = 0; blockRow < 9; blockRow += 3) {
            for(int blockCol = 0; blockCol < 9; blockCol += 3) {
                vector<int> t(10, 0);
                
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        char cell = board[blockRow + i][blockCol + j];
                        if(cell != '.') {
                            if(t[cell - '0'] == 0) t[cell - '0']++;
                            else return 0;
                        }
                    }
                }
                
            }
        }
        
        return 1;
    }
};
