class Solution {
public:
    int dp[100001][2][3];
    int recur(int i,vector<int>&p,bool choice,int transactions){
        if(i>=p.size() or transactions==0) return 0;
        if(dp[i][choice][transactions]!=-1) return dp[i][choice][transactions];
        int buy=INT_MIN,sell=INT_MIN;
        if(choice==false){
            int x=-p[i]+recur(i+1,p,true,transactions);
            int y=recur(i+1,p,false,transactions);
            buy=max(x,y);
        }
        else{
            int z=p[i]+recur(i+1,p,false,transactions-1);
            int w=recur(i+1,p,true,transactions);
            sell=max(z,w);
        }
        return dp[i][choice][transactions]=max(buy,sell);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return recur(0,prices,0,2);
    }
};