#include<bits/stdc++.h>

struct activities{
    int starting,finishing;
};

bool comparator(activities a1,activities a2){
    if(a1.finishing<a2.finishing)
        return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    
    struct activities activity[n];
    for(int i=0;i<n;i++){
        activity[i].starting=start[i];
        activity[i].finishing=finish[i];
    }
    
    sort(activity,activity+n,comparator);
    
    int maxActivities=1;
    int endLimit=activity[0].finishing;
    for(int i=1;i<n;i++){
        if(activity[i].starting>=endLimit){
             maxActivities++;
             endLimit=activity[i].finishing;
        }
           
        else
            continue;
    }
    
    return maxActivities;
}
