#include<bits/stdc++.h>
struct meeting{
        int starting,ending,pos;
};

bool comparator(meeting m1,meeting m2){
    if(m1.ending<m2.ending)
        return true;
    else if(m1.ending>m2.ending)
        return false;
    else if(m1.pos<m2.pos)
        return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n=start.size();
    
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].starting=start[i];
        meet[i].ending=end[i];
        meet[i].pos=(i+1);
    }
    
    sort(meet,meet+n,comparator);
    
    vector<int> ans;
    int endLimit=meet[0].ending;
    ans.push_back(meet[0].pos);
    
    for(int i=1;i<n;i++){
        if(meet[i].starting>endLimit){
            ans.push_back(meet[i].pos);
            endLimit=meet[i].ending;
        }
        else
            continue;
    }
    
    return ans;
}
