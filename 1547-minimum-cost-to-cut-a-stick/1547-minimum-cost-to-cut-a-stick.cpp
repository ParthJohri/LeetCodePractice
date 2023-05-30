class Solution {
public:
    int recur(vector<vector<int>>&dp,vector<int>&cuts,int start, int end){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            int cost=cuts[end+1]-cuts[start-1];
            int left=recur(dp,cuts,start,i-1);
            int right=recur(dp,cuts,i+1,end);
            ans=min(ans,cost+left+right);
        }
        return dp[start][end]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int l=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(l+1,vector<int>(l+1,-1));
        return recur(dp,cuts,1,l);
    }
};