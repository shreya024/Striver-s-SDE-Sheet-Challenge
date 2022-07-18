#include<queue>


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>> min_heap;
    for(int i=0;i<k;i++){
        for(int j=0;j<kArrays[i].size();j++){
            min_heap.push(kArrays[i][j]);
        }
    }
    
    vector<int> ans;
    while(min_heap.size()>0){
        ans.push_back(min_heap.top());
        min_heap.pop();
    }
    
    return ans;
}
