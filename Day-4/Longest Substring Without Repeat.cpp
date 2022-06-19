/*Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.
Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.*/


//Method 1 ---Find all Substrings T.C=O(N^2) & S.C=O(N)

include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
       
    
    int n=input.length();
    int maxLen=0;
    for(int i=0;i<n;i++){
        unordered_set<int> m;
        for(int j=i;j<n;j++){
            if(m.find(input[j])!=m.end()){
                maxLen=max(maxLen,j-i);
                break;
            }
            else{
                m.insert(input[j]);    
            }
        }
    }
    return maxLen;
}



//Method 2 ---Using two pointers T.C=O(N) & S.C=O(N)

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{

    int n=input.length();
    int maxLen=0;
    int l=0;
    unordered_set<int> m;
    for(int r=0;r<n;r++){
        //if duplicate is found
        if(m.find(input[r])!=m.end()){
             while(l<r && m.find(input[r])!=m.end()){
                 m.erase(input[l]);
                 l++;
             }
        }
        
        m.insert(input[r]);
        maxLen=max(maxLen,r-l+1);  
        
    }
    return maxLen;
}
