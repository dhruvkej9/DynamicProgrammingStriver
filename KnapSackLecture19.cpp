#include <vector>
#include <iostream>
using namespace std;
int solve1(int ind,int W,vector<int> &weight, vector<int> &value,vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(weight[0] <= W) return value[0];
        else return 0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    int notpick = solve1(ind-1,W,weight,value,dp);
    int pick = INT_MIN;
    if(weight[ind] <= W) pick = value[ind] + solve1(ind-1,W-weight[ind],weight,value,dp);
    
    return dp[ind][W] = max(pick,notpick);
}
int solve2(vector<int> wt, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight + 1,0));
    for(int W = wt[0];W <= maxWeight;W++) dp[0][W] = value[0];
    
    for(int ind = 1;ind < n;ind++)
    {
        for(int W = 0;W <= maxWeight;W++)
        {
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W)
            {
                take = value[ind] + dp[ind-1][W-wt[ind]];
            }
            dp[ind][W] = max(take,notTake);
        }
    }
    return dp[n-1][maxWeight];
}
int solve3(vector<int> wt, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight + 1,0),cur(maxWeight+1,0);
    for(int W = wt[0];W <= maxWeight;W++) prev[W] = value[0];
    
    for(int ind = 1;ind < n;ind++)
    {
        for(int W = 0;W <= maxWeight;W++)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W)
            {
                take = value[ind] + prev[W-wt[ind]];
            }
            cur[W] = max(take,notTake);
        }
        prev = cur;
    }
    return prev[maxWeight];
}
int solve4(vector<int> wt, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight + 1,0);
    for(int W = wt[0];W <= maxWeight;W++) prev[W] = value[0];
    
    for(int ind = 1;ind < n;ind++)
    {
        for(int W = maxWeight;W >= 0;W--)
        {
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W)
            {
                take = value[ind] + prev[W-wt[ind]];
            }
            prev[W] = max(take,notTake);
        }
    }
    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight + 1,-1));
// 	return solve1(n-1,maxWeight,weight,value,dp);
//     return solve2(weight,value,n,maxWeight);
//     return solve3(weight,value,n,maxWeight);
    return solve4(weight,value,n,maxWeight);

}