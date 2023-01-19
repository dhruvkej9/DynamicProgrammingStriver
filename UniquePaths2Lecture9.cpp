#include "vector"
#include "iostream"
#include "array"
using namespace std;
int mod = (int)(1e9 + 7);
int solve1(int i,int j,vector<vector<int>> &mat,vector<vector<int>> dp)
{   // Memoization
    if(i >= 0 && j>=0 && mat[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = solve1(i-1,j,mat,dp);
    int left = solve1(i,j-1,mat,dp);
    return dp[i][j] = (up + left)%mod;
}
int solve2(int n, int m, vector< vector< int> > &mat)
{   // Tabulation
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else
            {
                int up = 0,left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = (up + left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
int solve3(int n, int m, vector< vector< int> > &mat)
{   // Space Optimization
    vector<int> prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int> cur(m,0);
        for(int j=0;j<m;j++)
        {
            if(mat[i][j] == -1) cur[j] = 0;
            else if(i == 0 && j == 0) cur[j] = 1;
            else
            {
                int up = 0,left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = cur[j-1];
                cur[j] = (up + left)%mod;
            }
        }
        prev = cur;
    }
    return prev[m-1];
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return solve1(n-1,m-1,mat,dp);
//     return solve2(n,m,mat);
//     return solve3(n,m,mat);
}