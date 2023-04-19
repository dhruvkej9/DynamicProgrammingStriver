#include <vector>
#include <iostream>  
#include <algorithm>  
#include <climits>  
using namespace std;
//https://bit.ly/3jNRzqX
bool isPalindrome(int i,int j,string &s)
{
    while(i < j)
    {
        if(s[i] != s[j]) return false;
        i++;j--;
    }
    return true;
}
int solve1(int i,int n,string &str)
{
    if(i == n) return 0;
    int minCost = INT_MAX;
    // i...j
    for(int j = i;j < n;j++)
    {
        if(isPalindrome(i, j, str))
        {
            int cost = 1 + solve1(j + 1,n,str);
            minCost = min(minCost,cost);
        }
    }
    return minCost;
}
int solve2(int i,int n,string &str,vector<int> &dp)
{
    if(i == n) return 0;
    int minCost = INT_MAX;
    if(dp[i] != -1) return dp[i];
    // i...j
    for(int j = i;j < n;j++)
    {
        if(isPalindrome(i, j, str))
        {
            int cost = 1 + solve2(j + 1,n,str,dp);
            minCost = min(minCost,cost);
        }
    }
    return dp[i] = minCost;
}
int solve3(string &str)
{
    int n = str.size();
    vector<int> dp(n+1,-1);
    dp[n] = 0;
    for(int i = n-1;i >= 0;i--)
    {
        int minCost = INT_MAX;
        for(int j = i;j < n;j++)
        {
            if(isPalindrome(i, j, str))
            {
                int cost = 1 + solve2(j + 1,n,str,dp);
                minCost = min(minCost,cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0]- 1;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    // vector<int> dp(n+1,-1);

    // return solve1(0,n,str,dp) - 1; 
    // does a partition at the end so we have to 
    // subtract 1 from the answer

    return solve3(str);
}
