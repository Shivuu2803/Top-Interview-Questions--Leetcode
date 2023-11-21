class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> myQueue;
        
        for (auto& x : matrix)
        {
            for (int m : x)
            {
                myQueue.push(m);
            }
        }
 
        while (--k != 0)
        {
            myQueue.pop();
        }

        return myQueue.top(); 
    }
};
