class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector <int>odd;
        vector <int>even;
        for(auto i:nums)
        {
            if(i&1)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            if((i&1)==0)
            {
                nums[i]=even.back();
                even.pop_back();
            }
            else
            {
                nums[i]=odd.back();
                odd.pop_back();
            }
        }
        return nums;
    }
};