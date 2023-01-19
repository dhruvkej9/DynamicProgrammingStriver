#include "bits/stdc++.h"
using namespace std;
int f(int n,vector<int> dp)
{
    if(n<=1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1,dp) + f(n-2,dp);
}
int main()
{
    int n;
    cin>>n;
    int prev2 = 0;
    int prev = 1;
    for(int i = 2;i<=n;i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    cout<<prev;
    return 0;
}