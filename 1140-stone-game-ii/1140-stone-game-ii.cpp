class Solution {
public:
    int recur(vector<vector<vector<int>>> &dp,vector<int>& p,int i,int m,int pl){
        if(i>=p.size()) return 0;
        if(dp[i][m][pl]!=-1) return dp[i][m][pl];
        int count=0,sum=0,result=(pl==0?INT_MIN:INT_MAX);
        for(int j=i;j<p.size();j++){
            sum+=p[j];
            count++;
            if(count>2*m) break;
            if(pl==0)
            result=max(result,sum+recur(dp,p,j+1,max(m,count),1));
            else
            result=min(result,recur(dp,p,j+1,max(m,count),0));
        }
        return dp[i][m][pl]=result;
    }
    int stoneGameII(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(101,vector<int>(2,-1)));
        return recur(dp,p,0,1,0);
    }
};