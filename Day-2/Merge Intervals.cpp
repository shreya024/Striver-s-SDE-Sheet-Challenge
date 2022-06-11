/*You are given N number of intervals, where each interval contains two integers denoting the start time and the end time for the interval.
The task is to merge all the overlapping intervals and return the list of merged intervals sorted by increasing order of their start time.
Two intervals [A,B] and [C,D] are said to be overlapping with each other if there is at least one integer that is covered by both of them.*/

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int length=intervals.size();
    
    sort(intervals.begin(),intervals.end());
    
    for(int i=0;i<length;i++){
        if(ans.empty() || ans.back()[1]<intervals[i][0]){
            vector<int> v={intervals[i][0],intervals[i][1]};
            ans.push_back(v);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    
    return ans;
}
