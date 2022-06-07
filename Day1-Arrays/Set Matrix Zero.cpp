/*Problem Statement
Given an ‘N’ x ‘M’ integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix. In particular, your task is to modify it in such a way that if a cell has a value 0 (matrix[i][j] == 0), then all the cells of the ith row and jth column should be changed to 0.
You must do it in place.*/

//Better Approach
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	int row_size=matrix.size();
        int row[row_size];
        for(int i=0;i<row_size;i++){
            row[i]=-1;
        }
        //Column Set
        int col_size=matrix[0].size();
        int col[col_size];
        for(int i=0;i<col_size;i++){
            col[i]=-1;
        }

        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }

        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    
}

//Optimal Approach
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	int row_size=matrix.size();
        int col_size=matrix[0].size();
        
        bool col=true;
        for(int i=0;i<row_size;i++){
            if(matrix[i][0]==0)
                col=false;
            for(int j=1;j<col_size;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=row_size-1;i>=0;i--){
            for(int j=col_size-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col==false)
                matrix[i][0]=0;
        }
    
}
