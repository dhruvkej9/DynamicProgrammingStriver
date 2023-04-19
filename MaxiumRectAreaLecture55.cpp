#include <vector>
#include <iostream>  
#include <algorithm>  
#include <climits>  
#include <stack>  
using namespace std;
//https://bit.ly/33HFz61
int RectArea(vector<int>& heights)
    {
        stack<int> st;
        int i = 0,ans = 0;
        int n = heights.size();
        heights.push_back(0);
        // considered so that when i == n, the whole stack is considered in the area.
        for(int i = 0;i <= n;i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int j = st.top();
                st.pop();
                int h = heights[j];
                if(st.empty())
                {
                    ans = max(ans, h * i);
                }
                else 
                {
                    int width = i - st.top() - 1;
                    ans = max(ans,width * h);
                }
            }
            st.push(i);
        }   
        return ans;
    }
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
	int maxArea = 0;
	vector<int> height(m,0);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(mat[i][j] == 1) height[j]++;
			else height[j] = 0;
		}
		int area = RectArea(height);
		maxArea = max(maxArea,area);
	}
	return maxArea;
}