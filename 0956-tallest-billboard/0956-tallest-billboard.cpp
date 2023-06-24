class Solution {
public:
    int recur(vector<int>&rods,int index,int val,vector<unordered_map<int,int>>&dp){
        if(index>=rods.size()) {
            if(val==0) return 0;
            return INT_MIN;
        }
        if(dp[index].find(val)!=dp[index].end()) return dp[index][val];
        int x=recur(rods,index+1,val,dp);
        int y=rods[index]+recur(rods,index+1,rods[index]+val,dp);
        int z=recur(rods,index+1,-rods[index]+val,dp);
        return dp[index][val]=max({x,y,z});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<unordered_map<int,int>> dp(n+1);
        return recur(rods,0,0,dp);
    }
};