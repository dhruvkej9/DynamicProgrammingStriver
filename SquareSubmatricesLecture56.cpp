#include <vector>
#include <iostream>  
#include <algorithm>  
#include <climits>  
using namespace std;
//https://www.codingninjas.com/codestudio/problems/count-square-submatrices-with-all-ones_3751502?source=youtube&campaign=striver_dp_videos&leftPanelTab=1
int countSquares(int n, int m, vector<vector<int>> &arr) 
{
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0;i < n;i++) dp[i][0] = arr[i][0];
    for(int j = 0;j < m;j++) dp[0][j] = arr[0][j];

    for(int i = 1;i < n;i++)
    {
        for(int j = 1;j < m;j++)
        {
            if(arr[i][j])
            {
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            }
            else dp[i][j] = 0;
        }
    }
    
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            sum += dp[i][j];
        }
    }
    return sum;
}


