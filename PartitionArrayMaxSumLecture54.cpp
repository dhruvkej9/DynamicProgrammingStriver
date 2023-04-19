#include <vector>
#include <iostream>  
#include <algorithm>  
#include <climits>  
using namespace std;
//https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255?leftPanelTab=1
int solve(int i,int k,vector<int> &num,vector<int> &dp)
{
    if(i == num.size()) return 0;
    if(dp[i] != -1) return dp[i];

    int maxi = INT_MIN,maxans = 0,len = 0;
    for(int j = i;j < min(i + k,(int)num.size());j++)
    {
        len++;
        maxi = max(maxi,num[j]);
        int ans = len * maxi + solve(j + 1,k,num,dp);
        maxans = max(ans,maxans);
    } 
    return dp[i] = maxans;
}
int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n + 1,0);
    for(int i = n-1;i >= 0;i--)
    {
        int maxi = INT_MIN,maxans = INT_MIN,len = 0;
        for(int j = i;j < min(i + k,(int)num.size());j++)
        {
            len++;
            maxi = max(maxi,num[j]);
            int ans = len * maxi + dp[j + 1];
            maxans = max(ans,maxans);
        } 
        dp[i] = maxans;
    }
    return dp[0];
    // return solve(0,k,num,dp);
}