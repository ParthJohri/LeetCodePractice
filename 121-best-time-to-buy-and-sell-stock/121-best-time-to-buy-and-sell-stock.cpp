class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0,right=1,profit=0,maxProfit=0;
        // left = Buying of the stock
        // right = Selling if the stock
        while(right<prices.size())
        {
            if(prices[left]<prices[right])
            {
                profit=prices[right]-prices[left];
                maxProfit=max(profit,maxProfit);
            }
            else
                left=right;
            right++;
        }
        return maxProfit;
    }
};