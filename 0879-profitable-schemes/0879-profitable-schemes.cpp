class Solution {
public:
    int mod=1e9+7;
    int memo[202][303][404];
    int recur(int index,int profit, int groupsize, int n,int minProfit, vector<int>& group, vector<int>& p){
        if(index==group.size()) return profit>=minProfit;
        if(memo[index][groupsize][profit]!=-1) return memo[index][groupsize][profit];
        int ans,nottake,take=0;
        if(groupsize+group[index]<=n)
        take=recur(index+1,min(minProfit,profit+p[index]),groupsize+group[index],n,minProfit,group,p);
        nottake=recur(index+1,profit,groupsize,n,minProfit,group,p);
        ans=((long)take%mod+(long)nottake%mod)%mod;
        return memo[index][groupsize][profit]=ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo,-1,sizeof (memo));
        return recur(0,0,0,n,minProfit,group,profit);
    }
};