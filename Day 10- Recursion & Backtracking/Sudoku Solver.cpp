bool isSafe(int row,int col,int board[9][9],int val){
    for(int i=0;i<9;i++){
        if(board[row][i]==val||board[i][col]==val)
            return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            return false;
    }
    return true;
}

bool isItSudoku(int board[9][9]) {
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]==0){
                //cell is empty
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        bool solutionPossible=isItSudoku(board);
                        if(solutionPossible)
                            return true;
                        else
                            board[row][col]=0;//backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}
