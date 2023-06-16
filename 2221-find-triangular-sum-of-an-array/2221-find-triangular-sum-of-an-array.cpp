class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // 12345
        // 3579
        // 826
        // 08
        // 8
        int n=nums.size();
        if(n==1) return nums[0];
        vector<vector<int>> table;
        table.resize(n);
        table[n-1]=vector<int>(n,1);
        for(int j=0;j<n;j++){
            table[n-1][j]=nums[j];
        }
        for(int i=n-2;i>=0;i--){
            table[i]=vector<int>(i+1,1);
            for(int j=0;j<=i;j++){
                table[i][j]=(table[i+1][j]+table[i+1][j+1])%10;
            }
        }
        return table[0][0];
    }
};