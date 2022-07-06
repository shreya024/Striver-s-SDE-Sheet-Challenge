/*Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.
1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.
2. If he starts some chapter on a particular day he completes it that day itself.
3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.
Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.*/

bool isPossible(vector<int>time,int n,int m,long long int mid){
    int dayCount=1;
    long long int hourCount=0;
    for(int i=0;i<m;i++){
        if(hourCount+time[i]<=mid){
            hourCount+=time[i];
        }else{
            dayCount++;
            if(dayCount>n || time[i]>mid){
                return false;
            }
            hourCount=time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int s=0;
    long long int sum=0;
    for(int i=0;i<m;i++){
        sum+=time[i];
    }
    long long int e=sum;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;
    while(s<=e){
        if(isPossible(time,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
        mid=s+(e-s)/2;
    }
    return ans;
}
