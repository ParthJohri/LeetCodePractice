class Solution {
public:
    vector<vector<int>> p;
    int dp[1007];
    int recur(int index){
        if(index>=p.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick=0,ans=0;
        for(int i=index+1;i<p.size();i++){
            if(p[index][1]<p[i][0]){
                pick=recur(i);
            }
            ans = max(pick,ans);
        }
        return dp[index]=ans+1;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        p=pairs;
        int ans=INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<pairs.size();i++){
            ans=max(ans,recur(i));
        }
        return ans;
    }
};