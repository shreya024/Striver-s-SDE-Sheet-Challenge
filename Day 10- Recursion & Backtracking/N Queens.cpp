/*You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.*/

#include<bits/stdc++.h>

bool isSafe(int row,int col,vector<vector<int>>& board,int n){
    //Same Row Check
    int x=row,y=col;
    while(y>=0){
        if(board[x][y]==1)
            return false;
        y--;
    }
    
    //Checking for upward left diagonal
    x=row;y=col;
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
    
    //Checking for downward left diagonal
    x=row;y=col;
    while(x<n && y>=0){
        if(board[x][y]==1)
            return false;
        x++;
        y--;
    }
    
    return true;
}

void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board){
    vector<int> queens;
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            queens.push_back(board[i][j]);
        }
    }
    
    ans.push_back(queens);
}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    //base case
    if(col==n){
        addSolution(ans,board);
        return;
    }
    
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,ans,board,n);
            //backtrack
            board[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    solve(0,ans,board,n);
    return ans;
    
}
