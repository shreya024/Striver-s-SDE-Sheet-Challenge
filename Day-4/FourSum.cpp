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

//Method 2 ---Nested Loop+Two Pointer + Removing Duplicates

#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    vector<vector<int>> ans;
        vector<int> nums=arr;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            long long target3=target-nums[i];
            for(int j=i+1;j<n;j++){
                
                    long long target2=target3-nums[j];
                    
                    int left=j+1,right=n-1;
                    while(left<right){
                        long long two_sum=nums[left]+nums[right];
                        
                        if(two_sum<target2)
                            left++;
                        else if(two_sum>target2) 
                            right--;
                        else{
                            vector<int> q;
                            q.push_back(nums[i]);
                            q.push_back(nums[j]);
                            q.push_back(nums[left]);
                            q.push_back(nums[right]);
                            ans.push_back(q);
                            return "Yes";
                            //Removing duplicate 3rd element
                            while(left<right && q[2]==nums[left])
                                    left++;

                            //Removing dupliacte 4th element
                            while(left<right && q[3]==nums[right])
                                    right--;
                        }
                    }
                    //Removing duplicate 2nd element
                    while(j+1<n && nums[j]==nums[j+1])
                        j++;
            }
            //Removing duplicate 1st element
            while(i+1<n && nums[i]==nums[i+1])
                i++;
        }
        
        
        return "No";
    
}

