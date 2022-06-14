#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> res;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans^=i;
    }
    for(int i=0;i<arr.size();i++){
        ans^=arr[i];
    }
    
	int set_bit=ans&~(ans-1);
    
    int x=0,y=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]&set_bit)
            x^=arr[i];
        else
            y^=arr[i];
    }
    for(int i=1;i<=n;i++){
        if(i&set_bit)
            x^=i;
        else
            y^=i;
    }
    
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x)
            count++;
    }
    if(count)
        return {y,x};
    return {x,y};
}
