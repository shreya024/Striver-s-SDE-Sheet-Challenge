/*You have been given two integers ‘N’ and ‘K’. Your task is to find the K-th permutation sequence of numbers from 1 to ‘N’. The K-th permutation is the K-th permutation in the set of all sorted permutations of string 1 to ‘N’. */

//Method 1: Brute Force ---Using Recursion T.C=O(n*n!)
#include <bits/stdc++.h>

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

string kthPermutation(int n, int k) {
    vector<string> res;
    string s;
    for(int i=1;i<=n;i++){
        s.push_back(i+'0');
    }
    
    solve(s,0,res);
    sort(res.begin(),res.end());
    int index=res.begin()+k-1;
    string ans=res[index];
    return ans;
}

//Method 2: Using mathematics -> T.C=O(N^2)

string kthPermutation(int n, int k) {
    //Step 1: Computing (n-1) factorial and storing all the numbers
    
    int fact=1;
    vector<int> numbers;
    for(int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    
    string ans="";//for the actual answer
    k--;//logic is based on 0-based indexing
    
    //Step 2 : Computing each number
    while(true){
        ans+=to_string(numbers[k/fact]);//actual
        numbers.erase(numbers.begin()+k/fact);//deleting the already selected one
        if(numbers.size()==0)
            break;//till list is empty
        
        //Updating values
        k=k%fact;
        fact=fact/numbers.size();
    }
    
    return ans;
    
}
