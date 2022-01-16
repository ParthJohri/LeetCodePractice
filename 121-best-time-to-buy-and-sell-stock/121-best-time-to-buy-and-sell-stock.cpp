class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minv=INT_MAX;
        for(auto i:prices)
        {
            minv=min(minv,i);
            profit=max(profit,i-minv);
        }
    return profit;
    }
};