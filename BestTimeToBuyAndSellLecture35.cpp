#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//https://bit.ly/3rN7GIL
int maximumProfit(vector<int> &prices)
{
    int mini = prices[0];
    int n = prices.size();
    int maxProfit = 0;
    for(int i = 1;i < n;i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit,cost);
        mini = min(prices[i],mini);
    }
    return maxProfit;
}