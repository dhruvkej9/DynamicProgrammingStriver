#include <vector>
#include <iostream>
using namespace std;
int solve1(int ind,int T,vector<int> &arr,vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(T % arr[0] == 0) return T / arr[0];
        return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    int notTake = solve1(ind-1,T,arr,dp);
    int take = INT_MAX;
    
    if(arr[ind] <= T) take = 1 + solve1(ind,T - arr[ind],arr,dp);
    
    return dp[ind][T] = min(take,notTake);
}
int solve2(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp (n,vector<int>(target+1,-1));
    for(int T = 0;T<=target;T++)
    {
        if(T%arr[0] == 0) dp[0][T] = T / arr[0];
        else dp[0][T] = 1e9;
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int T = 0;T<=target;T++)
        {
            int notTake = dp[ind-1][T];
            int take = INT_MAX;
    
            if(arr[ind] <= T) take = 1 + dp[ind][T-arr[ind]];
    
            dp[ind][T] = min(take,notTake);
        }
    }
    return dp[n-1][target];
}
int solve3(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int> prev(target+1,0),cur(target+1,0);
    for(int T = 0;T<=target;T++)
    {
        if(T%arr[0] == 0) prev[T] = T / arr[0];
        else prev[T] = 1e9;
    }
    for(int ind = 1;ind < n;ind++)
    {
        for(int T = 0;T<=target;T++)
        {
            int notTake = prev[T];
            int take = INT_MAX;
    
            if(arr[ind] <= T) take = 1 + cur[T-arr[ind]];
    
            cur[T] = min(take,notTake);
        }
        prev = cur;
    }
    return prev[target];
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp (n,vector<int>(x+1,-1));
//     int ans = solve1(n-1,x,num,dp);
//     int ans = solve2(num,x);
    int ans = solve3(num,x);
    if(ans >= 1e9) return -1;
    return ans;
}