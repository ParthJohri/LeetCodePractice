class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(auto i:arr) sum+=i;
        if(sum%3!=0) return false;
        int avg=sum/3,nsum=0,count=0;
        for(auto i:arr) {
            nsum+=i;
            if(nsum==avg) {
                ++count;nsum=0;
            }
        }
        return count>=3;
    }
};