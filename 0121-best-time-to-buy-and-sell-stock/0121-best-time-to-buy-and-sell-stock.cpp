class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=prices[prices.size()-1],profit=0;
        for(int i=prices.size()-2;i>=0;i--){
            profit=max(profit,ans-prices[i]);
            ans=max(ans,prices[i]);
        }
        return profit;
    }
};