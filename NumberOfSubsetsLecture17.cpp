#include <vector>
#include <iostream>
using namespace std; 
int solve1(int ind,int sum,vector<int> &num,vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(sum == 0 && num[0] == 0) return 2;
        if(sum == 0 || sum == num[0]) return 1;
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int notTake = solve1(ind-1,sum,num,dp);
    int take = 0;
    if(num[ind] <= sum) take = solve1(ind-1,sum-num[ind],num,dp);
    
    return dp[ind][sum] = (take + notTake);
}
int solve2(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (tar + 1,0));
    for(int i = 0;i < n;i++)   
    {
        if(num[i] == 0) dp[i][0] = 2;
        else dp[i][0] = 1;
    }
    if(num[0] <= tar && num[0] != 0) dp[0][num[0]] = 1;
    for(int ind = 1;ind<n;ind++)
    {
        for(int sum = 0;sum <= tar;sum++)
        {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(num[ind] <= sum) take = dp[ind-1][sum - num[ind]];
    
            dp[ind][sum] = (take + notTake);
        }
    }
    return dp[n-1][tar];
}
int solve3(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1,0),cur(tar+1);
    if(num[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    
    cur = prev;
    if(num[0] <= tar && num[0] != 0) prev[num[0]] = 1;
    for(int ind = 1;ind<n;ind++)
    {
        for(int sum = 0;sum <= tar;sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum) take = prev[sum - num[ind]];
    
            cur[sum] = (take + notTake);
        }
        prev = cur;
    }
    return prev[tar];
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (tar + 1,-1));
//     return solve1(n-1,tar,num);
//     return solve1(n-1,tar,num,dp);
//     return solve2(num,tar);
    return solve3(num,tar);


}