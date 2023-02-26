class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int dp[time+10];
        memset(dp,time+1,sizeof dp);
        dp[0]=0;
        for(int t=1;t<=time;t++){
            for(auto i:clips){
                if(t>=i[0] and t<=i[1]){
                    dp[t]=min(dp[t],1+dp[i[0]]);
                }
            }
            if(dp[t]>=time+1) return -1;
        }
        return dp[time];
    }
};