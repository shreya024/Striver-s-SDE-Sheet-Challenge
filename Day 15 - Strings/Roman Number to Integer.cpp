#include <unordered_map>

int romanToInt(string s) {
    unordered_map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    
    int ans=0;
    
    for(int i=0;i<s.length()-1;i++){
        char prevch=s[i];
        char ch=s[i+1];
        if(m[prevch]>=m[ch]){
            ans+=m[prevch];
        }
        else
            ans-=m[prevch];
    }
    
    ans+=m[s[s.length()-1]];
    return ans;
}
