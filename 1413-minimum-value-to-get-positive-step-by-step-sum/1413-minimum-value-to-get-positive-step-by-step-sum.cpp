class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minval=INT_MAX,prefixsum=0;
        for(auto i: nums)
        {
            prefixsum+=i;
            minval=min(minval,prefixsum);
        }
        return minval>0?1:abs(minval)+1;
    }
};