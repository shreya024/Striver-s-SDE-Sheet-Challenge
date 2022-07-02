/*Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.*/

#include<bits/stdc++.h>

void solve(int index,int k,vector<int>arr,vector<vector<int>>&ans,vector<int>&v){
    //base case
    if(index>=arr.size()){
        if(k==0){
            ans.push_back(v);
        }
        return;
    }
    
    //include
    int element=arr[index];
    
        v.push_back(element);
        solve(index+1,k-element,arr,ans,v);
        v.pop_back();
    
    
    //exclude
    solve(index+1,k,arr,ans,v);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    solve(0,k,arr,ans,v);
    sort(ans.begin(),ans.end());
    return ans;
}
