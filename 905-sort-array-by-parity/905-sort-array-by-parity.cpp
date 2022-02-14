class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> arr;
        for(auto i: nums)
        {
            if((i&1)==0)
                arr.push_back(i);
        }
        for(auto i: nums)
        {
            if(i&1)
                arr.push_back(i);
        }
        return arr;
    }
};