#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//https://bit.ly/3rLHkqQ
int solve1(int ind,int buy,int cap,vector<int>& prices, int n,vector<vector<vector<int>>> &dp)
{
    if(cap == 0  || ind == n) return 0;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    if(buy)
    {
        return dp[ind][buy][cap] = max(-prices[ind] + solve1(ind+1,0,cap,prices,n,dp),
                solve1(ind + 1,1,cap,prices,n,dp));
    }
    return dp[ind][buy][cap] = max(prices[ind] + solve1(ind + 1,1,cap - 1,prices,n,dp),
            solve1(ind + 1,0,cap,prices,n,dp));
}
int solve2(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {
            for(int cap = 1;cap <= 2;cap++)
            {
                if(buy)
                {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                               dp[ind + 1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                    dp[ind + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
int solve3(vector<int>& prices, int n)
{
    vector<vector<int>> after(2,vector<int>(3,0));
    vector<vector<int>> cur(2,vector<int>(3,0));
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {
            for(int cap = 1;cap <= 2;cap++)
            {
                if(buy)
                {
                    cur[buy][cap] = max(-prices[ind] + after[0][cap],
                                               after[1][cap]);
                }
                else
                {
                    cur[buy][cap] = max(prices[ind] + after[1][cap - 1],
                                    after[0][cap]);
                }
            }
            after = cur;
        }
    }
    return after[1][2];
}
int solve4(int ind,int trans,vector<int>& prices, int n,vector<vector<int>> &dp)
{
    if(ind == n  || trans == 4) return 0;
    if(dp[ind][trans] != -1) return dp[ind][trans];
    if(trans%2 == 0)
    {
        return dp[ind][trans] = max(-prices[ind] + solve4(ind+1,trans + 1,prices,n,dp),
                solve4(ind + 1,trans,prices,n,dp));
    }
    return dp[ind][trans] = max(prices[ind] + solve4(ind + 1,trans + 1,prices,n,dp),
            solve4(ind + 1,trans,prices,n,dp));
}
int solve5(vector<int>& prices, int n)
{
    vector<vector<int>> dp(n+1,vector<int>(4+1,0));
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int trans = 3;trans >= 0;trans--)
        {
            if(trans%2 == 0)
            {
                dp[ind][trans] = max(-prices[ind] + dp[ind+1][trans+1],
                                            dp[ind+1][trans]);
            }
            else
            {
                dp[ind][trans] = max(prices[ind] + dp[ind+1][trans+1],
                                dp[ind+1][trans]);
            }
        }
    }
    return dp[0][0];
}
int solve6(vector<int>& prices, int n)
{
    vector<int> after(4+1,0);
    vector<int> cur(4+1,0);
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int trans = 3;trans >= 0;trans--)
        {
            if(trans%2 == 0)
            {
                cur[trans] = max(-prices[ind] + after[trans+1],
                                            after[trans]);
            }
            else
            {
                cur[trans] = max(prices[ind] + after[trans+1],
                                after[trans]);
            }
        }
        after = cur;
    }
    return after[0];
}
int maxProfit(vector<int>& prices, int n)
{
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // return solve1(0,1,2,prices,n,dp);
    // return solve2(prices,n);
    // return solve3(prices,n);
    // vector<vector<int>> dp(n+1,vector<int>(4,-1));
    // return solve4(0,0,prices,n,dp);
    return solve5(prices,n);
    // return solve6(prices,n);
}