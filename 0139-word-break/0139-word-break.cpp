class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        map<string,int> m;
        for(auto i:wordDict){
            m[i]++;
        }
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1; // Empty string is true
        for(int i=n-1;i>=0;i--){
            string word="";
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if(m.count(word)){
                    if(dp[j+1]) dp[i]=1;
                }
            }
        }
        return dp[0];
    }
};