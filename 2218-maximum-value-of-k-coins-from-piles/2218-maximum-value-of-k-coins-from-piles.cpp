class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
        function<int(int,int)> ans=[&](int index, int k){
            if(memo[index][k]!=-1) return memo[index][k];
            if(index>=n or k==0) return 0;
            int result=ans(index+1,k),curr=0;
            for(int j=0;j<k and j<piles[index].size();j++){
                curr+=piles[index][j];
                result=max(result,ans(index+1,k-j-1)+curr);
            }
            return memo[index][k]=result;
        };
        return ans(0,k);
    }
};