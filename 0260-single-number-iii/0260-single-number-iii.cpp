class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int aXORb=0;
        for(auto i:nums){
            aXORb^=i;
        }
        long long int lastBit=aXORb&(aXORb-1);
        long long int lastSetBit=lastBit^aXORb;
        int first=0,second=0;
        for(auto i:nums){
            if(i&lastSetBit) first^=i;
            else second^=i;
        }
        return {first,second};
    }
};