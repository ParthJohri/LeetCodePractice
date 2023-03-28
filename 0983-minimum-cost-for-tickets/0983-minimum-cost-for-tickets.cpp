class Solution {
public:
    int dp[1000005]={0};
    map<int,int> m;
    int recur(vector<int>& days, vector<int> costs, int index){
        if(index>=days.size()) return 0;
        int cost=INT_MAX;
        if(dp[index]!=0) return dp[index];
        for(int j=0;j<=2;j++){
            int lb=lower_bound(days.begin(),days.end(),days[index]+m[j])-days.begin();
            cost=min(cost,costs[j]+recur(days,costs,lb));
        }
        return dp[index]=cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        m={
            {0,1},{1,7},{2,30}
        };
        return recur(days,costs,0);
    }
};