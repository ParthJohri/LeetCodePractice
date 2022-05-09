class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int h=INT_MIN,sh=INT_MIN,l=INT_MAX,sl=INT_MAX;
        for(auto i:nums)
        {
            if(i>h||i>sh)
            {
                h=max(h,sh);
                sh=i;
            }
            if(i<l||i<sl)
            {
                l=min(l,sl);
                sl=i;
            }
        }
        return h*sh-l*sl;
    }
};