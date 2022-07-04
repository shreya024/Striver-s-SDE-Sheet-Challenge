/*You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.*/


bool safe(vector<vector<int>> &maze,vector<int> &visited,int n,int x,int y){
    if(x<0 || x>n-1 ||y<0 || y>n-1)
        return false;
    if(maze[x][y]==0)
        return false;
    if(visited[x*n+y]==1)
        return false;
    return true;
}

void solve(vector<vector<int>> &ans,vector<int> &visited,vector<vector<int>> maze,int n,int x,int y){
    //base case
    if(x==n-1 && y==n-1){
        visited[x*n+y]=1;
        ans.push_back(visited);
        visited[x*n+y]=0;
        return;
    }
    
    //Down
    if(safe(maze,visited,n,x+1,y)){
        visited[x*n+y]=1;
        solve(ans,visited,maze,n,x+1,y);
        
        //backtracking
        visited[x*n+y]=0;
    }
    
    //Left
    if(safe(maze,visited,n,x,y-1)){
        visited[x*n+y]=1;
        solve(ans,visited,maze,n,x,y-1);
        
        //backtracking
        visited[x*n+y]=0;
    }
    
    //Right
    if(safe(maze,visited,n,x,y+1)){
        visited[x*n+y]=1;
        solve(ans,visited,maze,n,x,y+1);
        
        //backtracking
        visited[x*n+y]=0;
    }
    
    //Up
    if(safe(maze,visited,n,x-1,y)){
        visited[x*n+y]=1;
        solve(ans,visited,maze,n,x-1,y);
        
        //backtracking
        visited[x*n+y]=0;
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> visited (n*n,0);
    if(maze[0][0] == 0)
           return ans;
    solve(ans,visited,maze,n,0,0);
    
    return ans;
}
