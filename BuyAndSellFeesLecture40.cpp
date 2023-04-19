#include <vector>
#include <iostream>  
using namespace std;
//https://bit.ly/3nZucNH
int maximumProfit(int n, int fee, vector<int> &prices)
{
    long aheadNotBuy,aheadBuy,curNotBuy,curBuy;
    aheadNotBuy = aheadBuy = 0;
    for(int ind = n-1;ind >= 0;ind--)
    {
        // sell
        curNotBuy = max(prices[ind] + aheadBuy,
                aheadNotBuy);
        // buy
        curBuy = max(-prices[ind] + aheadNotBuy - fee,
                aheadBuy);   
        
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}
