class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size()-1,row=0;
        while(row<matrix.size() && col>=0)
        {
            if(target==matrix[row][col]) 
                return true;
            else if(target<matrix[row][col])
                col--;
            else if(target>matrix[row][col])
                row++;
        }
        return false;
    }
};