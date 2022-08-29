class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int cols=0;cols<mat[0].size();cols++){
            vector<int> temp;
            int temprows=0,tempcols=cols;
            while(temprows<mat.size() and tempcols<mat[0].size()){
                temp.push_back(mat[temprows][tempcols]);
                temprows++;
                tempcols++;
            }
            sort(temp.begin(),temp.end());
            temprows=0,tempcols=cols;
            for(int i=0;i<temp.size();i++){    
                mat[temprows][tempcols]=temp[i];
                temprows++;
                tempcols++;
            }
        }
        for(int rows=1;rows<mat.size();rows++){
            vector<int> temp;
            int temprows=rows,tempcols=0;
            while(temprows<mat.size() and tempcols<mat[0].size()){
                temp.push_back(mat[temprows][tempcols]);
                temprows++;
                tempcols++;
            }
            sort(temp.begin(),temp.end());
            temprows=rows,tempcols=0;
            for(int i=0;i<temp.size();i++){
                mat[temprows][tempcols]=temp[i];
                temprows++;
                tempcols++;
            }
        }
        return mat;
    }
};