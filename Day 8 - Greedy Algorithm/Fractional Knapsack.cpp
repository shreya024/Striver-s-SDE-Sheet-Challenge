#include <bits/stdc++.h>

struct Allitems{
    int weight,value;
    double vpw;
};

bool comparator(Allitems i1,Allitems i2){
    if(i1.vpw>i2.vpw)
        return true;
    return false;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    struct Allitems item[n];
    for(int i=0;i<n;i++){
        item[i].weight=items[i].first;
        item[i].value=items[i].second;
        item[i].vpw=(double)item[i].value/(double)item[i].weight;
    }
    
    sort(item,item+n,comparator);
    int i=0;
    double knapsack=0;
    while(w!=0 && i<n){
        if(item[i].weight>w){
            knapsack+=(((double)w/(double)item[i].weight)*item[i].value);
            w-=w;
            break;
        }
        else{
            knapsack+=item[i].value;
            w-=item[i].weight;
        }
        i++;
    }
    
    return knapsack;
}
