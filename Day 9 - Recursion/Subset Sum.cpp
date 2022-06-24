/*You are given an array of ‘N’ integers. You have to find the sum of all the subsets in the non-decreasing order of the given array.
For Example
If N=3 and array elements are [1,2].
Following are the subset sums:
0 (by considering empty subset)
1 
2
1+2 = 3
So, subset sum are [0,1,2,3].*/


void solve(int index,vector<int> &num,vector<int> &subsets,int n,int sum){
    if(index==n){
         subsets.push_back(sum);
        return;
    }
    //not choosing the element
    solve(index+1,num,subsets,n,sum);
    //choosing the element
    solve(index+1,num,subsets,n,sum+num[index]);
    
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> subsets;
    int n=num.size();
    solve(0,num,subsets,n,0);
    sort(subsets.begin(),subsets.end());
    return subsets;
}
