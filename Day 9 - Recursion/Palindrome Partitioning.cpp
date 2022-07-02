/*You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.
Note: A substring is a contiguous segment of a string.
For Example:
For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.*/


#include <bits/stdc++.h>

bool isPalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void func(int index , string &s,vector<vector<string>>&ans,vector<string>&path)
{
    if(index==s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            func(i+1,s,ans,path);
            path.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>path;
    func(0,s,ans,path);
    return ans;
}
