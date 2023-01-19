#include <vector>
#include <iostream>
using namespace std;
int numberOfSubsets(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1,0),cur(tar+1);
    if(num[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(num[0] <= tar && num[0] != 0) prev[num[0]] = 1;
    for(int ind = 1;ind<n;ind++)
    {
        for(int sum = 0;sum <= tar;sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum) take = prev[sum - num[ind]];
    
            cur[sum] = (take + notTake);
        }
        prev = cur;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for(auto i : arr)
    {
        totalSum += i;
    }
    if((totalSum - d < 0) || (totalSum - d)%2) return 0;
    return numberOfSubsets(arr,(totalSum-d)/2);
}
int targetSum(int n, int target, vector<int>& arr)
{
    return countPartitions(n,target,arr);
}
