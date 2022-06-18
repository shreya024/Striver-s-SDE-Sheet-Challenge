//Method 1---Nested Loop+Binary Search --->T.L.E

class Solution {
private:
    bool binarySearch(vector<int> &nums,int low,int high,int element){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==element)
                return true;
            else if(nums[mid]<element)
                low++;
            else
                high--;
        }
        
        return false;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int element=(long long)target-(long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                    if(binarySearch(nums,k+1 , n-1, element)){
                        vector<int> q;
                        q.push_back(nums[i]);
                        q.push_back(nums[j]);
                        q.push_back(nums[k]);
                        q.push_back(element);
                        ans.insert(q);
                    }
                }
            }
        }
        
        
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
        
    }
};
