long double computeNthRoot(long double mid,int n){
    long double ans=1.0;
    while(n>0){
        ans*=mid;
        n--;
    }
    
    return ans;
}

double findNthRootOfM(int n, long long m) {
	long double s=1.0;
    long double e=m;
    
    long double esp=1e-9;
    while((e-s)>esp){
        long double mid=s+(e-s)/2.0;
        long double test=computeNthRoot(mid,n);
        if(test==m){
            return mid;
        }
        else if(test<m){
            s=mid;
        }
        else{
            e=mid;
        }
    }
    return s;
}
