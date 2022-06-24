/*For the given if ARR = [1,1,3],the answer will be [ ],[1],[1,1],[1,3],[3],[1,1,3].*/

#include<bits/stdc++.h>
void solve(int index,int n,vector<int>arr,vector<vector<int>>&ans,vector<int>&v){
    if(index==n){
        ans.push_back(v);
        return;
    }
    v.push_back(arr[index]);
    solve(index+1,n,arr,ans,v);
    v.pop_back();
    while(index+1<n && arr[index]==arr[index+1])
        index++;
    solve(index+1,n,arr,ans,v);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<int> v;
    vector<vector<int>> ans;
    solve(0,n,arr,ans,v);
    sort(ans.begin(),ans.end());
    return ans;
}
