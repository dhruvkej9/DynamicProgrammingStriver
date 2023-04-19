#include <iostream>
#include <vector> 
using namespace std;
//https://bit.ly/346R72e
int solve1(vector<int>& prices, int n,int k)
{
    vector<vector<int>> after(2,vector<int>(k + 1,0));
    vector<vector<int>> cur(2,vector<int>(k + 1,0));
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int buy = 0;buy <= 1;buy++)
        {
            for(int cap = 1;cap <= k;cap++)
            {
                if(buy)
                {
                    cur[buy][cap] = max(-prices[ind] + after[0][cap],
                                               after[1][cap]);
                }
                else
                {
                    cur[buy][cap] = max(prices[ind] + after[1][cap - 1],
                                    after[0][cap]);
                }
            }
            after = cur;
        }
    }
    return after[1][k];
}
int solve2(vector<int>& prices, int n,int k)
{
    vector<int> after(2*k + 1,0);
    vector<int>cur (2*k + 1,0);
    for(int ind = n-1;ind >= 0;ind--)
    {
        for(int trans = 2*k - 1;trans >= 0;trans--)
        {
            if(trans%2 == 0)
            {
                cur[trans] = max(-prices[ind] + after[trans + 1],
                                            after[trans]);
            }
            else
            {
                cur[trans] = max(prices[ind] + after[trans + 1],
                                after[trans]);
            }
            after = cur;
        }
    }
    return after[0];
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    return solve1(prices,n,k);
    // return solve2(prices,n,k);
}
