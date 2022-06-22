int removeDuplicates(vector<int> &arr, int n) {
    
    int count=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[count]){
            count++;
            arr[count]=arr[i];
        }  
    }
	
    return count+1;
}
