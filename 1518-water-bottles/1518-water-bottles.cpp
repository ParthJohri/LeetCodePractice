class Solution {
public:
    int numWaterBottles(int &numBottles, int &numExchange) {
        int sum=0,empty=0,exchange=0;
        while(numBottles!=0)
        {
          sum+=numBottles;
          empty+=numBottles;
          numBottles=empty/numExchange;
          empty=empty%numExchange;
        }
        return sum;
    }
};