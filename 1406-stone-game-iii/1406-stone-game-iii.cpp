class Solution {
public:
    int recur(vector<vector<int>> &dp,vector<int>& p,int i,int pl){
        if(i>=p.size()) return 0;
        if(dp[i][pl]!=-1) return dp[i][pl];
        int result;
        if(pl==0){
            int one=p[i]+recur(dp,p,i+1,1);
            int two=(i+1>=p.size()?INT_MIN:p[i]+p[i+1]+recur(dp,p,i+2,1));
            int three=(i+2>=p.size()?INT_MIN:p[i]+p[i+1]+p[i+2]+recur(dp,p,i+3,1));
            result=max({one,two,three});
        }
        else{
            int one=recur(dp,p,i+1,0);
            int two=recur(dp,p,i+2,0);
            int three=recur(dp,p,i+3,0);
            result=min({one,two,three});
        }
        return dp[i][pl]=result;
    }
    string stoneGameIII(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        int alice=recur(dp,p,0,0);
        int sum=0;
        for(auto i:p) sum+=i;
        int bob=sum-alice;
        cout<<alice<<" "<<bob<<endl;
        if(alice>bob) return "Alice";
        else if(alice<bob) return "Bob";
        else return "Tie";
    }
};