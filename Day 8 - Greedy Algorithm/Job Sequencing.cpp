#include<bits/stdc++.h>

struct job{
  int deadline,profit,id;  
};

bool comparator(job j1,job j2){
    if(j1.profit>j2.profit)
        return true;
    return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    struct job j[n];
    int maxDeadline=0;
    for(int i=0;i<n;i++){
        j[i].deadline=jobs[i][0];
        maxDeadline=max(maxDeadline,j[i].deadline);
        j[i].profit=jobs[i][1];
        j[i].id=i+1;
    }
    
    sort(j,j+n,comparator);
    
    int res[maxDeadline+1];
    for(int i=0;i<=maxDeadline;i++){
        res[i]=-1;
    }
    
    int maxProfit=0;int countJobs=0;
    for(int i=0;i<n;i++){
        for(int k=j[i].deadline;k>0;k--){
            if(res[k]==-1){
                res[k]=j[i].id;
                countJobs++;
                maxProfit+=j[i].profit;
                break;
            }
        }
    }
    
    return maxProfit;
}
