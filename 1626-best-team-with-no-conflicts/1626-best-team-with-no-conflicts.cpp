class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0;i<scores.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        });
        int ans=0,n=v.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
           dp[i]=v[i].second;
            for(int j=0;j<i;j++){
                if(v[j].second>=v[i].second){
                    dp[i]=max(dp[i],dp[j]+v[i].second);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};