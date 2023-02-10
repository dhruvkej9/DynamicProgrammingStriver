#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// https://bit.ly/3qXtORt
bool solve1(int i,int j,string &pattern,string &text)
{
   if(i < 0 && j < 0) return true;
   if(i < 0 && j >= 0) return false;
   if(j < 0 && i >= 0)
   {
     for (int ii = 0; ii <= i; ii++) {
       if (pattern[ii] != '*')
         return false;
     }
     return true;
   }

   if(pattern[i] == text[j] || pattern[i] == '?')
   {
      return solve1(i-1,j-1,pattern,text);
   }
   if(pattern[i] == '*')
   {
      return solve1(i-1,j,pattern,text) | solve1(i,j-1,pattern,text);
   }
   return false;
}
bool solve2(int i,int j,string &pattern,string &text,
vector<vector<int>> &dp)
{ // 1 - Based Indexing
   if(i == 0 && j == 0) return true;
   if(i == 0 && j > 0) return false;
   if(j == 0 && i > 0)
   {
     for (int ii = 1; ii <= i; ii++) {
       if (pattern[ii-1] != '*')
         return false;
     }
     return true;
   }
   if(dp[i][j] != -1) return dp[i][j];
   if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')
   {
      return dp[i][j] = solve2(i-1,j-1,pattern,text,dp);
   }
   if(pattern[i-1] == '*')
   {
      return dp[i][j] = (solve2(i-1,j,pattern,text,dp) | solve2(i,j-1,pattern,text,dp));
   }
   return dp[i][j] = false;
}
bool solve3(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<bool>> dp(n+1,vector<bool>(m+1,-1));
   dp[0][0] = true;
   for(int j = 1;j <= m;j++)
   {
      dp[0][j] = false;
   }
   for(int i = 1;i <= n;i++)
   {
      bool flag = true;
      for(int ii = 1;ii <= i;ii++)
      {
        if (pattern[ii - 1] != '*')
        {
            flag = false;
            break;
        }
      }
      dp[i][0] = flag;
   }
   for(int i = 1;i <= n;i++)
   {
      for(int j = 1;j <= m;j++)
      {
         if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')
         {
            dp[i][j] = dp[i-1][j-1];
         }
         else if(pattern[i-1] == '*')
         {
            dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
         }
         else dp[i][j] = false;
      }
   }
   return dp[n][m];
}
bool solve4(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<bool> prev(m+1,0);
   vector<bool> curr(m+1,0);
   prev[0] = true;
   for(int j = 1;j <= m;j++)
   {
      prev[j] = false;
   }
   for(int i = 1;i <= n;i++)
   {
      bool flag = true;
      for(int ii = 1;ii <= i;ii++)
      {
        if (pattern[ii - 1] != '*')
        {
            flag = false;
            break;
        }
      }
      // for every row 
      // you are assigning the 0th column's value 
      curr[0] = flag;
      
      for(int j = 1;j <= m;j++)
      {
         if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')
         {
            curr[j] = prev[j-1];
         }
         else if(pattern[i-1] == '*')
         {
            curr[j] = (prev[j] | curr[j-1]);
         }
         else curr[j] = false;
      }
      prev = curr;
   }
   return prev[m];
}
bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
   // return solve1(n-1,m-1,pattern,text);
   // return solve2(n,m,pattern,text,dp);
   // return solve3(pattern,text);
   return solve4(pattern,text);
}
