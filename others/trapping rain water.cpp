class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if(n == 0)
        {
            return 0;
        }
        int left = 0, right = n-1;
        
        int maxLeft = 0, maxRight = 0;
        
        int ans = 0;
        
        while(left < right)
        {
            if(height[left] > maxLeft)
            {
                maxLeft = height[left];
            }
            if(height[right] >  maxRight)
            {
                maxRight = height[right];
            }
            if(maxLeft < maxRight)
            {
                ans += max(0, maxLeft - height[left]);
                left++;
            }
            else
            {
                ans += max(0, maxRight - height[right]);
                right--;
            }
        }
        return ans;
    }
};
