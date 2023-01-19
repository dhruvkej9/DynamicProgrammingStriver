#include <bits/stdc++.h> 
using namespace std;
long long mod=1000000007;
int countDistinctWays(int nStairs) 
{
    long long prev = 1,prev2 = 1;
    for(int i = 2;i <= nStairs;i++)
    {
        long long curr = prev + prev2;
        curr %= mod;
        prev2 = prev;
        prev = curr;
    }
    return prev%mod;
}
int climbStairs(int n)
{
    if(n == 0 || n == 1) return 1;
    int prev = 1,prev2 = 1;
    for(int i = 2;i <= n;i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;    
}