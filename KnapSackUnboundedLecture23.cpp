#include <vector>
#include <iostream>
using namespace std;
int solve1(int ind,int W, vector<int> &val, vector<int> &wt,vector<vector<int>> dp)
{
    if(ind == 0)
    {
        return (int)(W/wt[0]) *  val[0];
    }
    if(dp[ind][W] != -1) return dp[ind][W] ;
    int notTake = solve1(ind-1,W,val,wt,dp);
    int take = 0;
    if(wt[ind] <= W)
    {
        take = val[ind] + solve1(ind,W-wt[ind],val,wt,dp);
    }
    return dp[ind][W]  = max(take,notTake);
}
int solve2(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(w+1,-1));
    for(int W = 0; W <= w;W++)
    {
        dp[0][W] = (int)(W/wt[0]) *  val[0];
    }
    for(int ind = 1;ind <n;ind++)
    {
        for(int W = 0;W <= w;W++)
        {
            int notTake = dp[ind-1][W];
            int take = 0;
            if(wt[ind] <= W)
            {
                take = val[ind] + dp[ind][W-wt[ind]];
            }
            dp[ind][W]  = max(take,notTake);
        }
    }
    return dp[n-1][w];
}
int solve3(int n, int w, vector<int> &val, vector<int> &wt)
{
//     vector<vector<int>> dp(n, vector<int>(w+1,-1));
    vector<int> prev(w+1,0),cur(w+1,0);
    for(int W = 0; W <= w;W++)
    {
        prev[W] = (int)(W/wt[0]) *  val[0];
    }
    for(int ind = 1;ind <n;ind++)
    {
        for(int W = 0;W <= w;W++)
        {
            int notTake = prev[W];
            int take = 0;
            if(wt[ind] <= W)
            {
                take = val[ind] + cur[W-wt[ind]];
            }
            cur[W]  = max(take,notTake);
        }
        prev = cur;
    }
    return prev[w];
}
int solve4(int n, int w, vector<int> &val, vector<int> &wt)
{
    // Only 1 Extra array
    vector<int> prev(w+1,0);
    for(int W = 0; W <= w;W++)
    {
        prev[W] = (int)(W/wt[0]) *  val[0];
    }
    for(int ind = 1;ind <n;ind++)
    {
        for(int W = 0;W <= w;W++)
        {
            int notTake = prev[W];
            int take = 0;
            if(wt[ind] <= W)
            {
                take = val[ind] + prev[W-wt[ind]];
            }
            prev[W]  = max(take,notTake);
        }
    }
    return prev[w];
}
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(w+1,-1));
//     return solve1(n-1,w,val,wt,dp);
//     return solve2(n,w,val,wt);
//     return solve3(n,w,val,wt);
    return solve4(n,w,val,wt);

}
