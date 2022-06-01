class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //1st Solution
        for(int i=0;i<matrix.size()-1;i++)
        {
            for(int j=0;j<matrix[0].size()-1;j++)
            {
                if(matrix[i][j]!=matrix[i+1][j+1])
                    return false;
            }
        }
        return true;
        // 2nd Solution
        // for(int i=1;i<matrix.size();i++)
        // {
        //     for(int j=1;j<matrix[0].size();j++)
        //     {
        //         if(matrix[i][j]!=matrix[i-1][j-1])
        //             return false;
        //     }
        // }
        // return true;
    }
};