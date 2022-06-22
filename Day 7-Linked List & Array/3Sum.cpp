#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    
	for(int i=0;i<n;i++){
        int target=K-arr[i];
        int j=i+1,k=n-1;
        while(j<k){
            if(arr[j]+arr[k]==target){
                vector<int> v;
                v.push_back(arr[i]);
                v.push_back(arr[j]);
                v.push_back(arr[k]);
                ans.push_back(v);
                while(arr[j]==v[1])
                    j++;
                while(arr[k]==v[2])
                    k--;
            }
            else if(arr[j]+arr[k]<target){
                j++;
            }
            else
                k--;
        }
        while(i<n && arr[i]==arr[i+1])
            i++;
        
    }
    
    return ans;
}
