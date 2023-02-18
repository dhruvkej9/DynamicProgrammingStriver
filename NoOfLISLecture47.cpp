#include <vector>
#include <iostream>  
using namespace std;
//https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1 
int findNumberOfLIS(vector<int> &arr)
{
    int maxi = 1;
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    for(int i = 0;i < n;i++)
    {
        for(int prev = 0;prev < i;prev++)
        {
            if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1;
                cnt[i] = cnt[prev];
            }
            else if(arr[i] > arr[prev] && dp[prev] + 1 == dp[i])
                //increase the count
                cnt[i] += cnt[prev];
        }
        maxi = max(maxi,dp[i]);
    }
    int nos = 0;
    for(int i = 0;i < n;i++)
    {
        if(dp[i] == maxi) nos += cnt[i];
    }
    return nos;
}