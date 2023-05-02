class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c1=0,c0=0,c1n=0;
        for(auto i:nums){
            if(i<0)
                ++c1n;
            else if(i==0)
                ++c0;
            else
                ++c1;
        }
        if(c0>0) return 0;
        else if(c1n%2!=0) return -1;
        return 1;
    }
};