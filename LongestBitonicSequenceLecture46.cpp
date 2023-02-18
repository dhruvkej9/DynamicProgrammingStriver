#include <vector>
#include <iostream>  
using namespace std;
// https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int longestBitonicSequence(vector<int>& arr, int n)\
{
	vector<int> dp1(n,1);
	for(int i = 0;i < n;i++)
	{
		for(int prev = 0; prev < i;prev++)
		{
			if(arr[prev] < arr[i] && dp1[i] < dp1[prev] + 1)
				dp1[i] = dp1[prev] + 1;
		}
	}	   
	int maxi = 1;
	vector<int> dp2(n,1);
	for(int i = n-1;i >= 0;i--)
	{
		for (int prev = n-1; prev > i; prev--)
		{
			if(arr[prev] < arr[i] && dp2[i] < dp2[prev] + 1)
				dp2[i] = dp2[prev] + 1;
		}
		maxi = max(maxi,dp1[i] + dp2[i] - 1);
	}
	return maxi;
} 
