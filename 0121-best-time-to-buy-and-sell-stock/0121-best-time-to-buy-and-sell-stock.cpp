class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),su[n],ans=0;
        su[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            su[i]=max(su[i+1],prices[i]);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,su[i]-prices[i]);
        }
        return ans;
    }
};