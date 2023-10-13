class Solution {
public:
    int dp[100000][2];
    int recur(int i,vector<int>&p,bool choice){
        if(i>=p.size()) return 0;
        if(dp[i][choice]!=-1) return dp[i][choice];
        int pick=INT_MIN,notpick=INT_MIN;
        if(choice==false){
            int x=-p[i]+recur(i+1,p,true);
            int y=recur(i+1,p,false);
            pick=max(x,y);
        }
        else{
            int z=p[i]+recur(i+1,p,false);
            int w=recur(i+1,p,true);
            notpick=max(z,w);
        }
        return dp[i][choice]=max(pick,notpick);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return recur(0,prices,0);
    }
};