int atoi(string str) {
    int ans=0;
    
    bool neg=false;
    if(str[0]=='-')
        neg=true;
    
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch>='0' && ch<='9'){
            ans=ans*10+(ch-'0');
        }
    }
    
    if(neg)
        ans=-ans;
    return ans;
}
