//Method 1- T.C=O(n^2)--->Codestudio

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            
            if(arr[i]+arr[j]==s){
                vector<int> sum;
                sum.push_back(min(arr[i],arr[j]));
                sum.push_back(max(arr[i],arr[j]));
                ans.push_back(sum);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

//Method 2- T.C=O(nlogn)--->LeetCode

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        v=nums;
        
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        int l=0,h=nums.size()-1;
        while(l!=h){
    
            if(nums[l]+nums[h]==target){
                break;
            }
            else if(nums[l]+nums[h]<target){
                l++;
            }
            else{
                h--;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(v[i]==nums[l])
                ans.push_back(i);
            else if(v[i]==nums[h])
                ans.push_back(i);
        }
    
    return ans;
    }
