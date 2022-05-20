class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int mx=INT_MIN,sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i+=2)
        {
            mx=max(mx,min(nums[i],nums[i+1]));
            sum+=mx;
        }
        return sum;
    }
};