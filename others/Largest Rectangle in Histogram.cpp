class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> stk;
        int maxArea = 0;
        int i = 0;

        while (i < heights.size()) 
        {
            if (stk.empty() || heights[i] >= heights[stk.top()]) 
            {
                stk.push(i);
                i++;
            } 
            else 
            {
                int top = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                int area = heights[top] * width;
                maxArea = max(maxArea, area);
            }
        }

        while (!stk.empty()) 
        {
            int top = stk.top();
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            int area = heights[top] * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
    
};
