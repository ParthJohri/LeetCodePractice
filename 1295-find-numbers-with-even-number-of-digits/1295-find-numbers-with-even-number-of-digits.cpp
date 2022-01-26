class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto i: nums)
        {
            if((to_string(i).length()&1)==0)
                ++count;
        }
        return count;
    }
};