class Solution {
public:
    int recur(vector<vector<int>>&events,int pos,int k,vector<vector<int>>&dp){
        if(pos>=events.size() or k<=0){
            return 0;
        }
        if(dp[pos][k]!=-1) return dp[pos][k];
        int takeit=0,nottake=0,ans=INT_MIN,i;
        for(i=pos+1;i<events.size();i++){
            if(events[i][0]>events[pos][1]){
                break;
            }
        }
        takeit=events[pos][2]+recur(events,i,k-1,dp);
        nottake=recur(events,pos+1,k,dp);
        ans=max(takeit,nottake);
        return dp[pos][k]=ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        return recur(events,0,k,dp);
    }
};