class Solution {
public:
    int dp[101];
    int recur(string& s,int index){
        // picking up index
        if(index>=s.length()){
            return 1;
        }
        if(s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];
        int pick=0,notpick=0;
        pick=recur(s,index+1);
        if(s.length()-index>1){
            string str=s.substr(index,2);
            int num = stoi(str);
            if(num<=26){
                notpick=recur(s,index+2);
            }
        }
        return dp[index]=pick+notpick;
    }
    int numDecodings(string s) {
        // 226
        // BZ
        // BBF
        // VF
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0') return 0;
        return recur(s,0);
    }
};