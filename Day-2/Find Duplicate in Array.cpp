#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    for(int i=0;i<arr.size();i++){
        ans[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(ans[i]>1)
            return i;
    }
}
