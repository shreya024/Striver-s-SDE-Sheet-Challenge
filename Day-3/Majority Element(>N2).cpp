/*You have been given an array/list 'ARR' consisting of 'N' integers. Your task is to find the majority element in the array. If there is no majority element present, print -1.*/

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    
    //Moore Voting Algorithm
	int count=0;
    int ele=0;
    for(int i=0;i<n;i++){
        if(count==0)
            ele=arr[i];
        if(ele==arr[i])
            count++;
        else
            count-=1;
    }
    
    count=0;
    for(int i=0;i<n;i++){
        if(ele==arr[i])
            count++;
    }
    if(count>n/2)
        return ele;
    else
        return -1;
}
