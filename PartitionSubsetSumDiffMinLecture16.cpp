#include <vector>
#include <iostream>
using namespace std; 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
    for(int i = 0;i < n;i++) totalSum += arr[i];
    int k = totalSum;
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i = 0;i < n;i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int ind = 1;ind <n;ind++)
    {
        for(int target = 1;target <= k;target++)
        {
            bool NotTake = dp[ind-1][target];
            bool take = false;
    
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
    
            dp[ind][target] = (NotTake | take); //(NotTake or take);
        }
    }
    //dp[n-1][col -> 0....totalSum]
    int mini = 1e9;
    for(int s1 = 0;s1 <= totalSum/2;s1++)
    {
        if(dp[n-1][s1])
        {
            mini = min(mini,abs((totalSum-s1) - s1));
        }
    }
    return mini;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
    for(int i = 0;i < n;i++) totalSum += arr[i];
    int k = totalSum;
    vector<bool> prev(k+1,0),cur(k+1,0);
    prev[0] = true;
    cur[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int ind = 1;ind <n;ind++)
    {
        for(int target = 1;target <= k;target++)
        {
            bool NotTake = prev[target];
            bool take = false;
    
            if(arr[ind] <= target) take = prev[target-arr[ind]];
    
            cur[target] = (NotTake | take);//(NotTake or take);
        }
        prev = cur;
    }
    //prev[col -> 0....totalSum]
    int mini = 1e9;
    for(int s1 = 0;s1 <= totalSum/2;s1++)
    {
        if(prev[s1])
        {
            mini = min(mini,abs((totalSum-s1) - s1));
        }
    }
    return mini;
}