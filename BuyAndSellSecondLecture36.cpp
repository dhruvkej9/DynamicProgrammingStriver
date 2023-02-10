#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//https://bit.ly/3nYO17H
long solve1(int ind,int buy,long *values,int n,vector<vector<long long>> &dp)
{
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    long profit = 0;
    if(buy)
    {
        profit = max(-values[ind] + solve1(ind+1,0,values,n,dp),
                solve1(ind+1,1,values,n,dp));
    }
    else
    {
        profit = max(values[ind] + solve1(ind+1,1,values,n,dp),
                solve1(ind+1,0,values,n,dp));
    }
    return dp[ind][buy] = profit;
}
long solve2(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
    dp[n][0] = dp[n][1] = 0;
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {

            long profit = 0;
            if(buy)
            {
                profit = max(-values[ind] + dp[ind+1][0],
                        dp[ind+1][1]);
            }
            else
            {
                profit = max(values[ind] + dp[ind+1][1],
                        dp[ind+1][0]);
            }
            dp[ind][buy] = profit;   
        }
    }
    return dp[0][1];
}
long solve3(long *values, int n)
{
    vector<long> ahead(2,-1),curr(2,-1);
    ahead[0] = ahead[1] = 0;
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {

            long profit = 0;
            if(buy)
            {
                profit = max(-values[ind] + ahead[0],
                        ahead[1]);
            }
            else
            {
                profit = max(values[ind] + ahead[1],
                        ahead[0]);
            }
            curr[buy] = profit;   
        }
        ahead = curr;
    }
    return ahead[1];
}
long solve4(long *values, int n)
{
    long aheadNotBuy,aheadBuy,curNotBuy,curBuy;
    aheadNotBuy = aheadBuy = 0;
    for(int ind = n-1;ind >= 0;ind--)
    {
        curNotBuy = max(values[ind] + aheadBuy,
                aheadNotBuy);
        curBuy = max(-values[ind] + aheadNotBuy,
                aheadBuy);   
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}
long getMaximumProfit(long *values, int n)
{
    // vector<vector<long long>> dp(n,vector<long long>(2,-1));
    // return solve1(0,1,values,n,dp);
    // return solve2(values,n);
    // return solve3(values,n);
    return solve4(values,n);

}