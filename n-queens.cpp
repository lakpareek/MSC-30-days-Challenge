class Solution {
private:
     
    
    void backtrack(int n, int row, vector<vector<string>>& res, vector<string>& board, unordered_set<int> cols, unordered_set<int> negDiag, unordered_set<int> posDiag){
        if(row==n){
            res.push_back(board);
            return ; 
        }
        
        for(int col = 0; col < n; col++){ 
            if( cols.find(col) != cols.end() ||
                negDiag.find(row - col) != negDiag.end() ||
                posDiag.find(row + col) != posDiag.end()    
              )
                continue;
            
            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);
            board[row][col] = 'Q';
            
            backtrack(n, row +1, res, board, cols, negDiag, posDiag);
            
            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
            board[row][col] = '.';
        }
    }
   
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols;    
        unordered_set<int> negDiag;  
        unordered_set<int> posDiag; 
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        backtrack(n, 0, res, board, cols, negDiag, posDiag);
        return res;
    }
};
