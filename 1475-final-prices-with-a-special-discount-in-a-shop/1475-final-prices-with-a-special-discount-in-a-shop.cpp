class Solution {
public:

    vector<int> finalPrices(vector<int>& prices) {
    vector<int> v;
    bool b=true;
    for(int i=0;i<prices.size()-1;i++)
     {
         for(int j=i+1;j<prices.size();j++)
             {
                 if(prices[i]>=prices[j])
                 {   b=false;
                     v.push_back(prices[i]-prices[j]);
                     break;
                 }
             }
             if(b)
                 v.push_back(prices[i]);
            b=true;
     }
        v.push_back(prices[prices.size()-1]);
        return v;
    }
};