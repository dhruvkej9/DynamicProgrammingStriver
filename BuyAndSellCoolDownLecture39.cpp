#include <vector>
#include <iostream> 
using namespace std;
int solve1(int ind,int buy,vector<int> &prices)
{
    if(ind >= prices.size()) return 0;
    if(buy == 1)
    {
        return max(-prices[ind] + solve1(ind + 1,0,prices),
                    solve1(ind + 1,1,prices));
    }
    return max(prices[ind] + solve1(ind + 2,1,prices),
                solve1(ind + 1,0,prices));
}
int solve2(int ind,int buy,vector<int> &prices,vector<vector<int>> &dp)
{
    if(ind >= prices.size()) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy == 1)
    {
        return dp[ind][buy] = max(-prices[ind] + solve2(ind + 1,0,prices,dp),
                    solve2(ind + 1,1,prices,dp));
    }
    return dp[ind][buy] = max(prices[ind] + solve2(ind + 2,1,prices,dp),
                solve2(ind + 1,0,prices,dp));
}
int solve3(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2,0));
    for(int ind = n-1;ind >= 0;ind--)
    {
        
        dp[ind][1] = max(-prices[ind] + dp[ind + 1][0],
                        dp[ind + 1][1]);
        dp[ind][0] = max(prices[ind] + dp[ind + 2][1],
                        dp[ind + 1][0]);
    }
    return dp[0][1];
}
int solve4(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front2(2,0);
    vector<int> front1(2,0);
    vector<int> cur(2,0);
    for(int ind = n-1;ind >= 0;ind--)
    {
        
        cur[1] = max(-prices[ind] + front1[0],
                        front1[1]);
        cur[0] = max(prices[ind] + front2[1],
                        front1[0]);
        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}
int stockProfit(vector<int> &prices) 
{
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2,-1));
    // return solve1(0,1,prices);
    // return solve2(0,1,prices,dp);
    return solve3(prices);
    // return solve4(prices);
}