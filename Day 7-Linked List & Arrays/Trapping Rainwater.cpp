#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> prefixLeftMax;
    vector<long> suffixRightMax;
    
    prefixLeftMax.push_back(arr[0]);
    for(int i=1;i<n;i++){
        prefixLeftMax.push_back(max(prefixLeftMax[i-1],arr[i]));
    }
    for(int i=0;i<n;i++){
        suffixRightMax.push_back(0);
    }
    suffixRightMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixRightMax[i]=max(suffixRightMax[i+1],arr[i]);
    }
    
    long waterTrapped=0;
    for(int i=0;i<n;i++){
        waterTrapped+=(min(prefixLeftMax[i],suffixRightMax[i])-arr[i]);
    }
    
    return waterTrapped;
}
