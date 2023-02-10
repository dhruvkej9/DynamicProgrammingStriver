#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//https://bit.ly/3HcTJdy
int solve1(int i,int j,string &s1,string &s2)
{
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(s1[i] == s2[j]) return solve1(i-1,j-1,s1,s2);

    return 1 + min(solve1(i-1,j,s1,s2),min(solve1(i-1,j-1,s1,s2),solve1(i,j-1,s1,s2)));
}
int solve2(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i == 0) return j;
    if(j == 0) return i;

    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1]) return dp[i][j] = solve2(i-1,j-1,s1,s2,dp);

    return dp[i][j] =  1 + min(solve2(i-1,j,s1,s2,dp),min(solve2(i-1,j-1,s1,s2,dp),solve2(i,j-1,s1,s2,dp)));
}
int solve3(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 0;i <= n;i++)
    {
        dp[i][0] = i;
    }
    for(int j = 0;j <= m;j++)
    {
        dp[0][j] = j;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] =  1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    return dp[n][m];
    
}
int solve4(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j = 0;j <= m;j++)
    {
        prev[j] = j;
    }
    for(int i = 1;i <= n;i++)
    {
        cur[0] = i; //
        for(int j = 1;j <= m;j++)
        {
            if(s1[i-1] == s2[j-1]) 
                cur[j] = prev[j-1];
            else 
                cur[j] =  1 + min(prev[j],min(prev[j-1],cur[j-1]));
        }
        prev = cur;
    }
    return prev[m];
    
}
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    // return solve1(n-1,m-1,str1,str2);
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return solve2(n,m,str1,str2,dp);
    // return solve3(str1,str2);
    return solve4(str1,str2);
}