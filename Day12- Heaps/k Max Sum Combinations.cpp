#include<queue>

void findKMax(vector<int>& nums, int k,vector<int> &ans) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
    for(int i=0;i<k;i++){
        ans.push_back(pq.top());
        pq.pop();
    }
}

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> combinations;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            combinations.push_back(a[i]+b[j]);
        }
    }
    
    vector<int> ans;
    findKMax(combinations,k,ans);
    return ans;
}
