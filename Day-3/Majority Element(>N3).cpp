#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int n=arr.size();
    
    //Extended Boyer Moore Voting Algorithm
    int count1=0,count2=0;
    int ele1=-1,ele2=-1;
    for(int i=0;i<n;i++){
        if(ele1==arr[i])
            count1++;
        else if(ele2==arr[i])
            count2++;
        else if(count1==0){
            ele1=arr[i];
            count1++;
        }
        else if(count2==0){
            ele2=arr[i];
            count2++;
        }
        else{
            count1-=1;
            count2-=1;
        }
    }
    
    count1=0;count2=0;
    for(int i=0;i<n;i++){
        if(ele1==arr[i])
            count1++;
        else if(ele2==arr[i])
            count2++;
    }
    vector<int> ans;
    if(count1>n/3)
        ans.push_back(ele1);
    if(count2>n/3)
        ans.push_back(ele2);
   
    return ans;
}
