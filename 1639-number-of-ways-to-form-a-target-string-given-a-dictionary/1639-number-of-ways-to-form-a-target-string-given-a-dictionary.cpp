class Solution {
public:
    int mod=1e9+7;
    int numWays(vector<string>& words, string target) {
        int n=target.length();
        vector<vector<int>> count(words[0].size()+1,vector<int>(27,0));
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(auto &i:words){
             for(int j=0;j<words[0].size();j++){
                count[j][i[j]-'a']++;
             }   
        }
        for(int i=0;i<words[0].size();i++){
            for(int j=n-1;j>=0;j--){
                dp[j]%=mod;
                count[i][target[j]-'a']%=mod;
                dp[j+1]+=(dp[j]*1ll*count[i][target[j]-'a'])%mod;
                dp[j+1]%=mod;
            }
        }
        return dp[n];
    }
};