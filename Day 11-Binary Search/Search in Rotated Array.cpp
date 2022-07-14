int findPivot(int* arr,int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        
        if(arr[mid]>=arr[0])
            s=mid+1;
        else
            e=mid;
        mid=s+(e-s)/2;
    }
    
    return s;
}

int bs(int * arr,int s,int e,int key){
    int mid=s+(e-s)/2;
    while(s<=e){
        
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            s=mid+1;
        else
            e=mid-1;
        mid=s+(e-s)/2;
    }
    
    return -1;
}

int search(int* arr, int n, int key) {
    //Find Pivot
    int pivotIndex=findPivot(arr,n);
    
    //Find Element
    int s1=pivotIndex;
    int e1=n-1;
    int s2=0;
    int e2=pivotIndex-1;
    
    int index=0;
    if(arr[s1]<=key && key<=arr[e1]){
        index=bs(arr,s1,e1,key);
    }
    else{
        index=bs(arr,s2,e2,key);
    }
    
    return index;
}
