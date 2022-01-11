class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> m1=matrix;
        int m=matrix.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][i]=m1[i][j];
            }
        }
        vector<vector<int>>m2=matrix;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=m2[i][m-1-j];
            }
        }
    }
};