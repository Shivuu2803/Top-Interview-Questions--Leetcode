class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        vector <int> vec;
        int row = matrix.size();
        
        int col = matrix[0].size();
        if (col <= 0)
        {
            return vec;
        }
        
        if (row <= 0)
        {
            return vec;
        }
        
        int r, c;
        for (r = 0, c = 0; r < (row+1)/2 && c < (col+1)/2; r++, c++)
        {
            for(int i = c; i < col-c; i++)
            {
                vec.push_back(matrix[r][i]);
            }
            
            for(int i = r+1; i < row-r; i++)
            {
                vec.push_back(matrix[i][col-c-1]);
            }
            
            for(int i = col-c-2; row-r-1 > r && i >= c; i--)
            {
                vec.push_back(matrix[row-r-1][i]);
            }
           
            for(int i = row-r-2; col-c-1 > c && i > r; i--)
            {
                vec.push_back(matrix[i][c]);
            }
        
        }
          
        return vec;
    }
};
