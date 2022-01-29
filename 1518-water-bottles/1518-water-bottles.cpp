class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=0,empty=0,exchange=0,nb=numBottles,ne=numExchange;
        while(nb!=0)
        {
          sum+=nb;
          empty+=nb;
          nb=empty/ne;
          empty=empty%ne;
        }
        return sum;
    }
};