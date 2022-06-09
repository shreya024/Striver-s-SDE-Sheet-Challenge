/*You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.*/

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int maxi=0;
    int mini=INT_MAX;
    for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        maxi=max(prices[i]-mini,maxi);
        
    }
    
    return maxi;
}
