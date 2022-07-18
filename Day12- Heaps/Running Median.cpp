#include<queue>

void findMedian(int *arr, int n)
{
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    for(int i=0;i<n;i++){
        
        if(maxheap.size()==0 ||arr[i]<maxheap.top())
            maxheap.push(arr[i]);
        else
            minheap.push(arr[i]);
        if(maxheap.size()>minheap.size()+1){
            
            minheap.push(maxheap.top());
            maxheap.pop();
            
        }
        else if(maxheap.size()<minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
        if(maxheap.size()==minheap.size()){
            cout<<(maxheap.top()+minheap.top())/2<<" ";
        }
        else
            cout<<maxheap.top()<<" ";
    }
}
