int calculateMinPatforms(int at[], int dt[], int n) {
    //Sorting both arrival and departure times
    
    sort(at,at+n);
    sort(dt,dt+n);
    
    int platform=1;
    int maxPlatform=1;
    
    int dp=0,ar=1;
    //Counting platforms on the basis of arrival and departure times
    while(ar<n && dp<n){
        if(at[ar]<=dt[dp]){
            platform++;  
            ar++;
        }
        else{
            dp++;
            platform--;
        }
        maxPlatform=max(maxPlatform,platform);
    }
   
    
    return maxPlatform;
}
