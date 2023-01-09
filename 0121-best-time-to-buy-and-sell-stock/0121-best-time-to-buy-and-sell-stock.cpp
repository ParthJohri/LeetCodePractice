class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        vector<int> sufarr(prices.size(),0);
        sufarr[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            sufarr[i]=max(prices[i],sufarr[i+1]);
        }    
        for(int i=0;i<prices.size();i++){
            int val=sufarr[i]-prices[i];
            ans=max(ans,val);
        }
        return ans;
    }
};