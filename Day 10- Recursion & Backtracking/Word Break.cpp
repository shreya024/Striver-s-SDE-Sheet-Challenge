bool isPresent(string temp,vector<string> &dictionary){
    
    for(int i=0;i<dictionary.size();i++){
        string d=dictionary[i];
        if(d==temp){
            return true;
        }
    }
    
    return false;
}

void solve(string &s,int index,vector<string> &dictionary,vector<string> &ans,string &curr){
    if(index>=s.size()){
        ans.push_back(curr);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        string temp=s.substr(index,i-index+1);
        
        //check if word is present in dictionary
        if(isPresent(temp,dictionary)){
            string x=curr;
            curr+=temp+" ";
            solve(s,i+1,dictionary,ans,curr);
            
            //backtrack;
            curr=x;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string curr;
    solve(s,0,dictionary,ans,curr);
    return ans;
    
}
