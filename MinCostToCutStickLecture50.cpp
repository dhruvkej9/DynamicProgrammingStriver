#include <vector>
#include <iostream>  
#include <algorithm>  
#include <climits>  
using namespace std;
// https://bit.ly/3rWLMnC
int solve1(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
{
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for(int ind = i;ind <= j;ind++)
    {
        int cost = cuts[j+1] - cuts[i-1] 
                   + solve1(i,ind - 1,cuts,dp)
                   + solve1(ind + 1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}
int solve2(int n, int c, vector<int> &cuts)
{
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    for(int i = c;i >= 1;i--)
    {
        for(int j = i;j <= c;j++)
        {
            // if(i > j) continue;
            int mini = INT_MAX;
            for(int ind = i;ind <= j;ind++)
            {
                int cost = cuts[j+1] - cuts[i-1] 
                        + dp[i][ind - 1]
                        + dp[ind + 1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.emplace_back(n);
    cuts.emplace(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    // vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    // return solve1(1,c,cuts,dp);
    return solve2(n,c,cuts);
}