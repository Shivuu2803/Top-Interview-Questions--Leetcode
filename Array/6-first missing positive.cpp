class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        set<int> mySet;
        int n = nums.size();
        
        for(int i = 0; i<n; i++)
        {
            mySet.insert(nums[i]);
        }
        
        int a = 1;
        
        while(a <= n)
        {
            if(mySet.find(a) != mySet.end())
            {
                a++;
            }
            else
            {
                return a;
            }
        }
        return a;
    }
};
