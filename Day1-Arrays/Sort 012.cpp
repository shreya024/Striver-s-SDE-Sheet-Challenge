void sort012(int *arr, int n)
{
   int count[3];
    for(int i=0;i<3;i++){
        count[i]=0;
    }
    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=0;i<count[0];i++){
        arr[i]=0;
    }
    for(int i=count[0];i<count[1]+count[0];i++){
        arr[i]=1;
    }
    for(int i=count[1]+count[0];i<n;i++){
        arr[i]=2;
    }
}
