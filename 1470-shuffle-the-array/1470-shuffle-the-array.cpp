class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> fh;
        vector<int> sh;
        for(int i=0;i<n;i++)
        {
            fh.push_back(nums[i]);
        }
        for(int i=n;i<nums.size();i++)
        {
            sh.push_back(nums[i]);
        }
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=fh[x];
            nums[++i]=sh[x];
            x++;
        }
        return nums;
    }
};