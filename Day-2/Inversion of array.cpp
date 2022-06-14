long long int merge(long long *arr,int s,int e){
    int mid=s+(e-s)/2;
    
    int len1=mid-s+1;
    int len2=e-mid;
    
    int *a=new int[len1];
    int *b=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        a[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        b[i]=arr[k++];
    }
    
    int i=0,j=0;
    k=s;long long int inv_count = 0;
    while(i<len1 && j<len2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++;k++;
        }
        else{
            arr[k]=b[j];
            j++;k++;
            inv_count+=len1- i;
        }
    }
    while(i<len1){
        arr[k]=a[i];
            i++;k++;
    }
    while(j<len2){
        arr[k]=b[j];
            j++;k++;
    }
    return inv_count;
}
long long ms(long long *arr,int s,int e){
    long long count_inv=0;
    if(s<e){
        int mid=s+(e-s)/2;
    //Sorting the left part
    count_inv+=ms(arr,s,mid);
    //Sorting the right part
    count_inv+=ms(arr,mid+1,e);
    
    //Merging the Sorted Arrays
    count_inv+=merge(arr,s,e);
    }
    
    return count_inv;
}

long long mergeSort(long long *arr, int n) {
    long long int count=ms(arr,0,n-1);;
    return count;
    
}
long long getInversions(long long *arr, int n){
    long long int count=mergeSort(arr,n);
    return count;
}
