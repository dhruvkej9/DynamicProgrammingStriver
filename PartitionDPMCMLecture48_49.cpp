#include <vector>
#include <iostream>  
using namespace std;
// https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?leftPanelTab=1
int solve1(int i,int j,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k = i;k < j;k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + 
                    solve1(i,k,arr,dp) + solve1(k+1,j,arr,dp);
        if(steps < mini) mini = steps;
    }
    return dp[i][j] = mini;
}
int solve2(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    for(int i = 1;i < N;i++) dp[i][i] = 0;
    for(int i = N-1;i>=1;i--)
    {
        for(int j = i+1;j<N;j++)
        {
            int mini = INT_MAX;
            for(int k = i;k <= j-1;k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}
int matrixMultiplication(vector<int>& arr, int N){
    
    vector<vector<int>> dp(N,vector<int>(N,-1));
    // return solve1(1,N-1,arr,dp);
    return solve2(arr,N); 
}