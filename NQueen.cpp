#include<bits/stdc++.h>
void add(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    vector<int> temp;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int r = row;
        int c = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 1) return false;
            row--;
            col--;
        }

        row = r;
        col = c;
        while(col >= 0){
            if(board[row][col] == 1) return false;
            col--;
        }

        row = r;
        col = c;
        while(row < n && col >= 0){
            if(board[row][col] == 1) return false;
            row++;
            col--;
        }
        
        return true;
}
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n){
        if(col == n){
            add(board, ans, n);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                solve(col + 1, board, ans, n);
                board[row][col] = 0; 
            }
        }
}
vector<vector<int>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        solve(0, board, ans, n);
        return ans;
    // Write your code here.
}