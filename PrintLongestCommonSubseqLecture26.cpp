#include <vector>
#include <iostream>
using namespace std;
void PrintString(string s,string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j = 0;j <=m;j++) dp[0][j] = 0;
    for(int i = 0;i <=n;i++) dp[i][0] = 0;
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
    
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int len = dp[n][m];
    string res = "";
    for(int i = 0;i < len;i++)
    {
        res += '$';
    }
    int i = n,j = m;
    int index = len-1;
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            res[index] = s[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<res<<endl;
}
int main()
{
    PrintString("abcde","bdgek");
    return 0;
}