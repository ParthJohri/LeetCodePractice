class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> n=nums;
        for(int i=0;i<nums.size();i++)
        {
            nums[(i+k)%nums.size()]=n[i];
        }
    }
};