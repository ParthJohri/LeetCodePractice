class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int k=0,x=0;
        for(int i=0;i<nums.size();i++)
           s.insert(nums[i]);
        vector<int> v(s.begin(),s.end());
        for(int i=0;i<v.size();i++)
        {
               nums[x++]=v[i];
               ++k;
        }
        return k;
    }
};