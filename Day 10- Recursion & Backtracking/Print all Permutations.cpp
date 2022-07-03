#include<bits/stdc++.h>

void solve(string &s,int index,vector<string> &res){
    //base case
    if(index==s.size()){
        res.push_back(s);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        swap(s[i],s[index]);
        solve(s,index+1,res);
        swap(s[i],s[index]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> res;
    solve(s,0,res);
    return res;
}
