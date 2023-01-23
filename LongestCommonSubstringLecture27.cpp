#include <vector>
#include <iostream>
using namespace std;
int lcs(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1,0),cur(m+1,0);
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i-1] == t[j-1]) 
            {
                cur[j] = 1 + prev[j-1];
                ans = max(ans,cur[j]);
            }
    
            else cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}