class Solution 
{
 public:
  int longestConsecutive(vector<int>& nums) 
  {
    int result = 0;
    unordered_set<int> set{nums.begin(), nums.end()};

    for (int x : nums) 
    {
      if (set.count(x - 1))
      {
          continue;
      } 
      int length = 1;
        
      while (set.count(++x))
      {
          ++length;
      }
      result = max(result, length);
    }

    return result;
  }
};
