class Solution {
public:
    int dp[1000011];
    int mod=1e9+7;
    int recur(string& s,int k,int index){
        if(index==s.length()) return 1;
        if(s[index]=='0') return 0;
        if(dp[index]!=0) return dp[index];
        long num=0,ans=0;
        for(int i=index;i<s.length();i++){
            num=num*10+(s[i]-'0');
            if(num>k) break;
            ans=(ans%mod+recur(s,k,i+1)%mod)%mod; 
        }
        return dp[index]=ans;
    }
    int numberOfArrays(string s, int k) {
        return recur(s,k,0);
    }
};