#include <vector>
#include <iostream>
using namespace std;
int solve1(int ind ,int n,vector<int> &price,vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        return n*price[0];
    }
    if(dp[ind][n] != -1) return dp[ind][n];
    int notTake = solve1(ind-1,n,price,dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if(rodlength <= n) take = price[ind] + solve1(ind,n-rodlength,price,dp);
    
    return dp[ind][n] = max(notTake,take);
    
}
int solve2(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    for(int N = 0;N <= n;N++)
    {
        dp[0][N] = N*price[0];
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int N = 0;N <= n;N++)
        {
             int notTake = dp[ind-1][N];
             int take = INT_MIN;
             int rodlength = ind + 1;
             if(rodlength <= N) take = price[ind] + dp[ind][N-rodlength];
    
            dp[ind][N] = max(notTake,take);
        }
    }
    return dp[n-1][n];
}
int solve3(vector<int> &price, int n)
{
//     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    vector<int> prev(n+1,0),cur(n+1,0);
    for(int N = 0;N <= n;N++)
    {
        prev[N] = N*price[0];
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int N = 0;N <= n;N++)
        {
             int notTake = prev[N];
             int take = INT_MIN;
             int rodlength = ind + 1;
             if(rodlength <= N) take = price[ind] + cur[N-rodlength];
    
            cur[N] = max(notTake,take);
        }
        prev = cur;
    }
    return prev[n];
}
int solve4(vector<int> &price, int n)
{
    vector<int> prev(n+1,0);
    for(int N = 0;N <= n;N++)
    {
        prev[N] = N*price[0];
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int N = 0;N <= n;N++)
        {
             int notTake = prev[N];
             int take = INT_MIN;
             int rodlength = ind + 1;
             if(rodlength <= N) take = price[ind] + prev[N-rodlength];
    
            prev[N] = max(notTake,take);
        }
    }
    return prev[n];
}
int cutRod(vector<int> &price, int n)
{
//     vector<vector<int>> dp(n,vector<int>(n+1,-1));
//     return solve1(n-1,n,price,dp);
//     return solve2(price,n);
//     return solve3(price,n);
    return solve4(price,n);
}
