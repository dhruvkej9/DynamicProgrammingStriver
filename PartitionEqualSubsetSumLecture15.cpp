#include <vector>
#include <iostream>
using namespace std; 
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool>prev(k+1,0),cur(k+1,0);
    prev[0] = true;
    cur[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int ind = 1;ind <n;ind++)
    {
        if(prev[k] == true)
        {
            return true;
        }
        for(int target = 1;target <= k;target++)
        {
            bool NotTake = prev[target];
            bool take = false;
    
            if(arr[ind] <= target) take = prev[target-arr[ind]];
    
            cur[target] = (NotTake || take);
        }
        prev = cur;
    }
    return prev[k];
}
bool canPartition(vector<int> &arr, int n)
{
	int totalSum = 0;
    for(int i = 0;i < n;i++) totalSum += arr[i];
    
    if(totalSum%2) return false;
    int target = totalSum/2;
    
    return subsetSumToK(n,target,arr);
}
