class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector< vector<int> > arr(n+1, vector<int> (n+1, 0)); 
        vector< vector <int> > col(n+1, vector<int> (n+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i+1][matrix[i][j]]++;
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                col[matrix[i][j]][j+1]++;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(arr[i][j]!=1||col[i][j]!=1)
                    return false;
            }
        }
        return true;
    }
};