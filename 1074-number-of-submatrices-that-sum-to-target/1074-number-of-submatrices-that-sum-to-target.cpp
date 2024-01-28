class Solution {
public:
    int subarraySumOfFixedTarget(vector<int>&nums,int target){
        int ans=0,prefixsum=0;
        map<int,int> m;
        m[0]=1;
        for(auto i:nums){
            prefixsum+=i;
            ans+=m[prefixsum-target];
            m[prefixsum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size(),ans=0;
        for(int i=0;i<col;i++){
            vector<int> prefix(row,0);
            for(int j=i;j<col;j++){
                // 0 to col matlab puri matrix
                // 1 to col matlab 1 se col tak 0 column include nhi
               for(int k=0;k<row;k++){
                    prefix[k]+=matrix[k][j];
                }
                ans+=subarraySumOfFixedTarget(prefix,target);
            }
        }
        return ans;
    }
};