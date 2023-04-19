#include <vector>
#include <iostream>  
#include <algorithm>  
#include <climits>  
using namespace std;
//https://bit.ly/32tAMUW
using namespace std;
int mod = 1e9 + 7;
long long solve1(int i,int j,int isTrue,string & exp)
{
    if(i > j) return 0;
    if(i == j)
    {
        if(isTrue)
        {
            return exp[i] == 'T';
        }
        else return exp[i] == 'F';
    }
    long long ways = 0;
    for(int ind = i+1;ind <= j-1;ind+=2)
    {
        long long lT = solve1(i,ind - 1,1,exp);
        long long lF = solve1(i,ind - 1,0,exp);
        long long rT = solve1(ind + 1,j,1,exp);
        long long rF = solve1(ind + 1,j,0,exp);

        if(exp[ind] == '&')
        {
            if(isTrue) ways = (ways + (rT * lT)%mod)%mod;
            else ways = (ways + (rT * lF)%mod + (lT * rF)%mod
                        + (rF * lF)%mod)%mod;
        }
        else if(exp[ind] == '|')
        {
            if(isTrue) ways = (ways + (rT * lF)%mod + (lT * rF)%mod
                                + (rT * lT)%mod)%mod;
            else ways = (ways + (rF * lF)%mod)%mod;
        }
        else
        {
            if(isTrue) ways = (ways + (rT * lF)%mod + (lT * rF)%mod)%mod;
            else ways = (ways + (rT * lT)%mod + (lF * rF)%mod)%mod;
        }
    }
    return ways;
}
long long solve2(int i,int j,int isTrue,string & exp,vector<vector<vector<long long>>> &dp)
{
    if(i > j) return 0;
    if(i == j)
    {
        if(isTrue)
        {
            return exp[i] == 'T';
        }
        else return exp[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    long long ways = 0;
    for(int ind = i+1;ind <= j-1;ind+=2)
    {
        long long lT = solve2(i,ind - 1,1,exp,dp);
        long long lF = solve2(i,ind - 1,0,exp,dp);
        long long rT = solve2(ind + 1,j,1,exp,dp);
        long long rF = solve2(ind + 1,j,0,exp,dp);

        if(exp[ind] == '&')
        {
            if(isTrue) ways = (ways + (rT * lT)%mod)%mod;
            else ways = (ways + (rT * lF)%mod + (lT * rF)%mod
                        + (rF * lF)%mod)%mod;
        }
        else if(exp[ind] == '|')
        {
            if(isTrue) ways = (ways + (rT * lF)%mod + (lT * rF)%mod
                                + (rT * lT)%mod)%mod;
            else ways = (ways + (rF * lF)%mod)%mod;
        }
        else
        {
            if(isTrue) ways = (ways + (rT * lF)%mod + (lT * rF)%mod)%mod;
            else ways = (ways + (rT * lT)%mod + (lF * rF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] =  ways;
}
int solve3(string &exp)
{
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n + 1,vector<vector<long long>>(n + 1,vector<long long>(2,0)));
    for(int i = 0;i < n;i++)
    {
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }
    for(int i = n-1;i >= 0;i--)
    {
        for(int j = i+1;j <= n-1;j++)
        {
            for(int isTrue = 0;isTrue <= 1;isTrue++)
            {
                long long ways = 0;
                for(int ind = i+1;ind <= j-1;ind+=2)
                {
                    long long lT = dp[i][ind - 1][1];
                    long long lF = dp[i][ind - 1][0];
                    long long rT = dp[ind + 1][j][1];
                    long long rF = dp[ind + 1][j][0];

                    if(exp[ind] == '&')
                    {
                        if(isTrue) ways = (ways + (rT * lT)%mod)%mod;
                        else ways = (ways + (rT * lF)%mod + (lT * rF)%mod
                                    + (rF * lF)%mod)%mod;
                    }
                    else if(exp[ind] == '|')
                    {
                        if(isTrue) ways = (ways + (rT * lF)%mod + (lT * rF)%mod
                                            + (rT * lT)%mod)%mod;
                        else ways = (ways + (rF * lF)%mod)%mod;
                    }
                    else
                    {
                        if(isTrue) ways = (ways + (rT * lF)%mod + (lT * rF)%mod)%mod;
                        else ways = (ways + (rT * lT)%mod + (lF * rF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] =  ways;
            }
        }
    }
    return dp[0][n-1][1];
}
int evaluateExp(string &exp)
{
    int n = exp.size();
    // vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    // return solve1(0,n-1,1,exp);
    // return solve2(0,n-1,1,exp,dp);
    return solve3(exp);
}