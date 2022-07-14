int uniqueElement(vector<int> arr, int n)
{
	int s=0;
    int e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid-1]!=arr[mid] &&  arr[mid]!=arr[mid+1])
            return arr[mid];
        else if((arr[mid]==arr[mid+1] && mid%2==0)||(arr[mid]==arr[mid-1] && mid%2==1))
            s=mid+1;
        else
            e=mid-1;
    }
}
