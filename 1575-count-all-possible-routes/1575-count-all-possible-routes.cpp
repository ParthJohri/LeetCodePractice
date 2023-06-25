class Solution {
public:
    int mod=1e9+7;
    int recur(vector<int>&locations,int fuel,int curr,int finish,vector<vector<int>>&dp){
        if(fuel<0) return 0;
        if(dp[curr][fuel]!=-1) return dp[curr][fuel];
        long long ans=0;
        if(finish == curr) ans=1;
        for(int i=0;i<locations.size();i++){
            if(i!=curr){
                ans=ans%mod+recur(locations,fuel-abs(locations[i]-locations[curr]),i,finish,dp)%mod;
                ans%=mod;
            }
        }
        return dp[curr][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(n+1,vector<int>(201,-1));
        return recur(locations,fuel,start,finish,dp)%mod;
    }
};