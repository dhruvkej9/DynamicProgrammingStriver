#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solve1(int i,int j,string &s,string &t,vector<vector<int>> &dp)
{
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i-1] == t[j-1])  return 1 + solve1(i-1,j-1,s,t,dp);
    
    return dp[i][j] = max(solve1(i-1,j,s,t,dp),solve1(i,j-1,s,t,dp));
}
int solve2(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j = 0;j <=m;j++) dp[0][j] = 0;
    for(int i = 0;i <=n;i++) dp[i][0] = 0;
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
    
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int solve3(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j = 0;j <=m;j++) prev[j] = 0;
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
    
            else cur[j] = max(prev[j],cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     return solve1(n,m,s,t,dp);
    return solve2(s,t);
    // return solve3(s,t);
}
int longestPalindromeSubsequence(string s)
{
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minInsertion(string &str)
{
    return str.size() - longestPalindromeSubsequence(str);
}