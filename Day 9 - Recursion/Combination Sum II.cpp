/*You are given an array ‘Arr’ of ‘N’ positive integers. You are also given a positive integer ‘target’.
Your task is to find all unique combinations of the array ‘Arr’ whose sum is equal to ‘target’. Each number in ‘Arr’ may only be used once in the combination.
Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.*/

#include<bits/stdc++.h>

void solve(int index,int k,vector<int>arr,vector<vector<int>>&ans,vector<int>&v){
    //base case
    
        if(k==0){
            
            ans.push_back(v);
        }
   
    
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1])
            continue;
        int element=arr[i];
        if(element>k)
            break;
        v.push_back(element);
        solve(i+1,k-element,arr,ans,v);
        v.pop_back();
    }  
 
}



vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<vector<int>> ans;
    vector<int> v;
    
    sort(arr.begin(),arr.end());
    solve(0,target,arr,ans,v);
    return ans;
}


