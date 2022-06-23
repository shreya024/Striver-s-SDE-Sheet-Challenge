int findMinimumCoins(int amount) 
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    
    int minCoins=0;
    for(int i=8;i>=0;i--){
        if(amount==0)
            break;
        if(amount/coins[i]){
            minCoins+=amount/coins[i];
            amount=amount%coins[i];
        }
        
    }
    
    return minCoins;
}
