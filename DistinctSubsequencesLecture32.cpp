#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//https://bit.ly/3nZNxy7
int solve1(int i,int j,string &s,string &t,vector<vector<int>> &dp)
{
    if(j == 0) return 1;
    if(i == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1])
    {
        return dp[i][j] = (solve1(i-1,j-1,s,t,dp) + solve1(i-1,j,s,t,dp));
    } 
    return dp[i][j] = solve1(i-1,j,s,t,dp);
}
int solve2(string &s,string &t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<double>> dp(n+1,vector<double>(m+1,0));
    for(int i = 0;i <= n;i++) dp[i][0] = 1;
    // for(int j = 1;j <= m;j++) dp[0][j] = 0;
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } 
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[n][m];
}
int solve3(string &s,string &t)
{
    int n = s.size();
    int m = t.size();
    vector<double> prev(m+1,0),cur(m+1,0);
    prev[0] = cur[0] = 1;

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i-1] == t[j-1])
            {
                cur[j] = prev[j-1] + prev[j];
            } 
            else
            {
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }
    return (int)prev[m];
}
int solve4(string &s,string &t)
{
    int n = s.size();
    int m = t.size();
    vector<double> dp(m+1,0);
    dp[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = m;j >= 1;j--)
        {
            if(s[i-1] == t[j-1])
            {
                dp[j] += dp[j-1];
            } 
        }
    }
    return (int)dp[m];
}

long long numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return solve1(n,m,s,t,dp);
    // return solve2(s,t);
    // return solve3(s,t);
    return solve4(s,t);
}