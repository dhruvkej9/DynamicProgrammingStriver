#include <vector>
#include <iostream>
using namespace std; 
int solve1(int i,int j,vector<vector<int>> &matrix)
{
    if(j<0 || j>= matrix[0].size()) return -1e8;
    if(i == 0) return matrix[0][j];
    
    int up = matrix[i][j] + solve1(i-1,j,matrix);
    int LeftDiagonal = matrix[i][j] + solve1(i-1,j-1,matrix);
    int RightDiagonal = matrix[i][j] + solve1(i-1,j+1,matrix);
    
    return max(up,max(LeftDiagonal,RightDiagonal));
}
int solve2(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    if(j<0 || j>= matrix[0].size()) return -1e8;
    if(i == 0) return matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    int up = matrix[i][j] + solve2(i-1,j,matrix,dp);
    int LeftDiagonal = matrix[i][j] + solve2(i-1,j-1,matrix,dp);
    int RightDiagonal = matrix[i][j] + solve2(i-1,j+1,matrix,dp);
    
    return dp[i][j] =  max(up,max(LeftDiagonal,RightDiagonal));
}
int solve3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>> dp(n,vector<int> (m,0));
    
    for(int j = 0;j < m;j++) dp[0][j] = matrix[0][j];
    for(int i = 1;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            int up = matrix[i][j] + dp[i-1][j];
           
            int LeftDiagonal = matrix[i][j];
            if(j-1>= 0) LeftDiagonal += dp[i-1][j-1];
            else LeftDiagonal += -1e8;
            
            int RightDiagonal = matrix[i][j];
            if(j+1<m) RightDiagonal +=dp[i-1][j+1];
            else RightDiagonal += -1e8;
            
            dp[i][j] = max(up,max(RightDiagonal,LeftDiagonal));
        }
    }
    for(int j = 0;j < m;j++)
    {
        maxi = max(maxi,dp[n-1][j]); 
    }
    return maxi;
}
int solve4(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<int> prev(m,0),cur(m,0);
    
    for(int j = 0;j < m;j++) prev[j] = matrix[0][j];
    for(int i = 1;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            int up = matrix[i][j] + prev[j];
           
            int LeftDiagonal = matrix[i][j];
            if(j-1>= 0) LeftDiagonal += prev[j-1];
            else LeftDiagonal += -1e8;
            
            int RightDiagonal = matrix[i][j];
            if(j+1<m) RightDiagonal += prev[j+1];
            else RightDiagonal += -1e8;
            
            cur[j] = max(up,max(RightDiagonal,LeftDiagonal));
        }
        prev = cur;
    }
    for(int j = 0;j < m;j++)
    {
        maxi = max(maxi,prev[j]); 
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>> dp(n,vector<int> (m,-1));
//     for(int j = 0;j < m;j++)
//     {
//         maxi = max(maxi,solve1(n-1,j,matrix,dp)); 
//     }
//     for(int j = 0;j < m;j++)
//     {
//         maxi = max(maxi,solve2(n-1,j,matrix,dp)); 
//     }
//     return maxi;
    
    return solve4(matrix);
    
}