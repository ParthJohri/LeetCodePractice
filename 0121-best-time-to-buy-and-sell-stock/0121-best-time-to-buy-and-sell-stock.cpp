class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),sellingPrice=prices[n-1],ans=0;
        for(int i=n-2;i>=0;i--){
            ans=max(ans,sellingPrice-prices[i]);
            sellingPrice=max(sellingPrice,prices[i]);
        }
        return ans;
    }
};