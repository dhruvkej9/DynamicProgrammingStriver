#include <vector>
#include <iostream>
using namespace std; 
bool solve1(int ind,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool NotTake = solve1(ind-1,target,arr,dp);
    bool take = false;
    
    if(arr[ind] <= target) take = solve1(ind-1,target-arr[ind],arr,dp);
    
    return dp[ind][target] = (NotTake || take);
}
bool solve2(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i = 0;i < n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind = 1;ind <n;ind++)
    {
        for(int target = 1;target <= k;target++)
        {
            bool NotTake = dp[ind-1][target];
            bool take = false;
    
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
    
            dp[ind][target] = (NotTake || take);
        }
    }
    return dp[n-1][k];
}
bool solve3(int n, int k, vector<int> &arr)
{
    vector<bool>prev(k+1,0),cur(k+1,0);
    prev[0] = true;
    cur[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int ind = 1;ind <n;ind++)
    {
        if(prev[k] == true)
        {
            return true;
        }
        for(int target = 1;target <= k;target++)
        {
            bool NotTake = prev[target];
            bool take = false;
    
            if(arr[ind] <= target) take = prev[target-arr[ind]];
    
            cur[target] = (NotTake || take);
        }
        prev = cur;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
//     return solve1(n-1,k,arr,dp);
//     return solve2(n,k,arr);
    return solve3(n,k,arr);

}