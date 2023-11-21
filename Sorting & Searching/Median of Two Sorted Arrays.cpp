class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) 
        {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size(), l = 0, r = m, K = (m + n + 1) / 2;
        
        while (true) 
        {
            int i = (l + r) / 2, j = K - i;
            if (i < m && nums2[j - 1] > nums1[i]) 
            {
                l = i + 1;  
            } 
            else if (i > l && nums1[i - 1] > nums2[j]) 
            {
                r = i - 1;
            } 
            else 
            {
                int leftMax = max(i ? nums1[i - 1] : INT_MIN, j ? nums2[j - 1] : INT_MIN);
                if ((m + n) % 2) 
                {
                    return leftMax;
                }
                int rightMax = min(i == m ? INT_MAX : nums1[i], j == n ? INT_MAX : nums2[j]);
                return (leftMax + rightMax) / 2.00;  
            }
        }
    }
};
