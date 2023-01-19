#include <vector>
#include <iostream> 
using namespace std;
int solve1(int i,int j ,vector<vector<int>>& triangle, int n)
{
    if(i == n-1)
    {
        return triangle[n-1][j];
    }
    int down = triangle[i][j] + solve1(i+1,j,triangle,n);
    int diagonal = triangle[i][j] + solve1(i+1,j+1,triangle,n);
    
    return min(down,diagonal);
}
int solve2(int i,int j ,vector<vector<int>>& triangle, int n,vector<vector<int>> dp)
{
    if(i == n-1)
    {
        return triangle[n-1][j];
    }
    if(dp[i][j] != -1) return dp[i][j];
    
    int down = triangle[i][j] + solve2(i+1,j,triangle,n,dp);
    int diagonal = triangle[i][j] + solve2(i+1,j+1,triangle,n,dp);
    
    return dp[i][j] = min(down,diagonal);
}
int solve3(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int j = 0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
    for(int i = n-2;i>=0;i--)
    {
        for(int j = i;j >= 0;j--)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,diagonal);
        }
    }
    return dp[0][0];
}
int solve4(vector<vector<int>>& triangle, int n)
{
    vector<int> front(n,0);
    for(int j = 0;j<n;j++) front[j] = triangle[n-1][j];
    for(int i = n-2;i>=0;i--)
    {    vector<int> curr(n,0);
        for(int j = i;j >= 0;j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];
            curr[j] = min(down,diagonal);
        }
     front = curr;
    }
    return front[0];
}
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
//     return solve1(0,0,triangle,n);
//     return solve2(0,0,triangle,n,dp);
//     return solve3(triangle,n);
    return solve4(triangle,n);
}