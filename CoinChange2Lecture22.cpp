#include <vector>
#include <iostream>
using namespace std;
long solve1(int ind,int T,int * a,vector<vector<long>> &dp)
{
    if(ind == 0)
    {
        return (T%a[0] == 0);
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    long nonTake = solve1(ind-1,T,a,dp);
    long take = 0;
    if(a[ind] <= T) take = solve1(ind,T - a[ind],a,dp);
    
    return dp[ind][T] = (nonTake + take);
}
long solve2(int *a, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value + 1,-1));
    for(int T = 0;T <= value;T++)
    {
        dp[0][T] = (T%a[0] == 0);
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int T = 0;T<= value;T++)
        {
            long nonTake = dp[ind-1][T];
            long take = 0;
            if(a[ind] <= T) take = dp[ind][T-a[ind]];
    
            dp[ind][T] = (nonTake + take);
        }
    }
    return dp[n-1][value];
}
long solve3(int *a, int n, int value)
{
    vector<long> prev(value + 1,0),cur(value+1,0);
    for(int T = 0;T <= value;T++)
    {
        prev[T] = (T%a[0] == 0);
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int T = 0;T<= value;T++)
        {
            long nonTake = prev[T];
            long take = 0;
            if(a[ind] <= T) take = cur[T-a[ind]];
    
            cur[T] = (nonTake + take);
        }
        prev = cur;
    }
    return prev[value];
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value + 1,-1));
//     return solve1(n-1,value,denominations,dp);
//     return solve2(denominations,n,value);
    return solve3(denominations,n,value);
}