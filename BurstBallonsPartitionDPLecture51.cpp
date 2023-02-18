#include <bits/stdc++.h> 
int solve1(int i,int j,vector<int>& a,vector<vector<int>> &dp)
{
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int maxi = INT_MIN;
	for(int ind = i;ind <= j;ind++)
	{
		int cost = a[i-1]*a[ind]*a[j+1] + 
				   solve1(i,ind - 1,a,dp) + 
				   solve1(ind + 1,j,a,dp);
		maxi = max(maxi,cost);
	}
	return dp[i][j] = maxi;
}
int solve2(vector<int>& a)
{
	int n = a.size();
	a.emplace_back(1);
	a.emplace(a.begin(),1);
	vector<vector<int>> dp(n + 2,vector<int>(n + 2,0));
	for(int i = n;i >= 1;i--)
	{
		for(int j = 1;j <= n;j++)
		{   // j == n so size is n + 2
			if(i > j) continue;
			int maxi = INT_MIN;
			for(int ind = i;ind <= j;ind++)
			{
				int cost = a[i-1]*a[ind]*a[j+1] + 
							dp[i][ind - 1] + 
							dp[ind + 1][j];
				maxi = max(maxi,cost);
			}
			dp[i][j] = maxi;
		}
	}
	return dp[1][n];
}
int maxCoins(vector<int>& a)
{
	int n = a.size();
	// a.emplace_back(1);
	// a.emplace(a.begin(),1);
	// vector<vector<int>> dp(n + 1,vector<int>(n+1,-1));
	// return solve1(1,n,a,dp);
	return solve2(a);
}