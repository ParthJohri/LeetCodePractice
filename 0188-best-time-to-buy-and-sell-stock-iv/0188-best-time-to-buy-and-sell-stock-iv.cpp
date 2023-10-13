class Solution {
public:
    int dp[1001][2][101];
    int recur(int i,vector<int>&p,int choice,int t){
        if(i>=p.size() or t==0) return 0;
        if(dp[i][choice][t]!=-1) return dp[i][choice][t];
        int buy=INT_MIN,sell=INT_MIN;
        if(choice==false){
            int x=-p[i]+recur(i+1,p,true,t);
            int y=recur(i+1,p,false,t);
            buy=max(x,y);
        }
        else{
            int z=p[i]+recur(i+1,p,false,t-1);
            int w=recur(i+1,p,true,t);
            sell=max(z,w);
        }
        return dp[i][choice][t]=max(buy,sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return recur(0,prices,0,k);
    }
};