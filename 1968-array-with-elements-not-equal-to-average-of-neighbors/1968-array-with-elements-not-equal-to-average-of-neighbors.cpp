class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i-1]+nums[i+1]==2*nums[i])
                swap(nums[i],nums[i+1]);
        }
        for(int i=nums.size()-2;i>=1;i--)
        {
            if(nums[i-1]+nums[i+1]==2*nums[i])
                swap(nums[i],nums[i-1]);
        }
        // Wiggle Sort 
        // Time Complexity : O(NlogN)
        // Space Complexity : O(N)
        // vector<int> v(nums);
        // sort(v.begin(),v.end());
        // int n=nums.size();
        // n=n%2==0?n-2:n-1;
        // int x=0;
        // for(int i=n;i>=0;i-=2)
        // {
        //     nums[i]=v[x++];
        // }
        // n=nums.size();
        // n=n%2==0?n-1:n-2;
        // for(int i=n;i>=1;i-=2)
        // {
        //     nums[i]=v[x++];
        // }
        return nums;
    }
};