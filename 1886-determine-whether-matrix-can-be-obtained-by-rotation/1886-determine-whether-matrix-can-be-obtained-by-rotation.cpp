class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
      vector<vector<int>> m=mat;
        int n=mat.size();
        int count=0;
    while(count<4)
{for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int temp=mat[i][j];
                mat[i][j]=mat[i][n-1-j];
                mat[i][n-1-j]=temp;
            }
        }
        if(mat==target)
            return true;count++;}
            return false;
    }
};