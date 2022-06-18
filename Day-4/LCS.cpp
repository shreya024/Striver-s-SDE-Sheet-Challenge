//Method 1 --- Using loop

#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(arr.size()==0)
        return 0;
    sort(arr.begin(),arr.end());
    
    int lcs_length=1;
    int curr_length=1;
    int prev=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]==prev+1)
            curr_length++;
        else if(arr[i]!=prev){
            curr_length=1;
        }
        prev=arr[i];
        lcs_length=max(lcs_length,curr_length);
    }
    
    return lcs_length;
}
