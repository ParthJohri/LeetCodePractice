class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        for(auto i:nums)
        {
            for(auto j:nums)
            {
                if(abs(i-j)==k)
                    ++count;
            }
        }
        return count/2;
    }
};