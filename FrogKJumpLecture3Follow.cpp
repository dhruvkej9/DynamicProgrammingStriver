#include "vector"
#include <iostream>
#include <climits>
using namespace std;
int solve(int index,vector<int> arr,int k,vector<int> &dp)
{
  if(index == 0) return 0;
  int ans = INT_MAX;
  if(dp[index] != -1) return dp[index];
  for(int i=1;i<=k;i++)
  {
    if(index-i>=0)
    {
        ans = min(ans,solve(index-i,arr,k%index,dp) + abs(arr[index] - arr[index - i]));
        // cout<<ans<<" ";
    }
  }
  return dp[index] = ans;
}
#include "vector"
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    for(int index = 1;index <= n-1;index++)
    {
        // int ans = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(index-j>=0)
            {
                dp[index] = min(dp[index],dp[index-j] + abs(arr[index] - arr[index - j]));
            }
        }
        // dp[index] = ans;
    }
    cout<<dp[n-1];
    return 0;
}