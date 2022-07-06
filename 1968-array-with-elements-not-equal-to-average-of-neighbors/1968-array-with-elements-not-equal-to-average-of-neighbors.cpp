class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int n=nums.size();
        n=n%2==0?n-2:n-1;
        int x=0;
        for(int i=n;i>=0;i-=2)
        {
            nums[i]=v[x++];
        }
        n=nums.size();
        n=n%2==0?n-1:n-2;
        for(int i=n;i>=1;i-=2)
        {
            nums[i]=v[x++];
        }
        return nums;
    }
};