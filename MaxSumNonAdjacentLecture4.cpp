#include <bits/stdc++.h>
using namespace std;
int solveMemiozation(int ind,vector<int> &nums,vector<int> &dp)
{
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    int pick = nums[ind] + solve(ind-2,nums,dp);
    int notpick = 0 + solve(ind-1,nums,dp);
    
    return dp[ind] = max(pick,notpick);
}
int solveTabulation(vector<int> &nums,vector<int> &dp)
{
    int n = nums.size();
    dp[0] = nums[0];
    for(int i=1;i<n;i++)
    {
        int take = nums[i];
        if(i>1) take += dp[i-2];
        
        int nottake = 0 + dp[1-1];
        
        dp[i] = max(nottake,take);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int take = nums[i];
        if(i>1) take += prev2;
        
        int nottake = 0 + prev;
        
        int curi = max(nottake,take);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}