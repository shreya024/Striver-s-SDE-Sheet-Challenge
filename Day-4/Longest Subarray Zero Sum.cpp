/*Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.*/


#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int,int> m;
    int sum=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0){
            maxi=i+1;
        }
        else{
            if(m.find(sum)!=m.end()){
                maxi=max(maxi,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
    }
    return maxi;

}
