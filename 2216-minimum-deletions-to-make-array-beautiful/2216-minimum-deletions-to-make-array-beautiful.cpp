class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if((i-count)%2==0 && nums[i+1]==nums[i]) ++count;
        }
        if(nums[n-2]==nums[n-1] &&(n-1-count)%2==0) ++count;
        if((n-count)%2!=0) ++count;
        return count;
    }
};