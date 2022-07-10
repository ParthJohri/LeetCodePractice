class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size(),localsum=0,globalsum=INT_MIN,localmin=0,globalmin=INT_MAX;
        // Kadane's Algorithm DP 
        for(int i=0;i<n;i++) {
            localsum=max(nums[i],nums[i]+localsum);
            globalsum=max(globalsum,localsum);
        }
        for(int i=0;i<n;i++) {
            localmin=min(nums[i],nums[i]+localmin);
            globalmin=min(globalmin,localmin);
        }
        return max(globalsum,abs(globalmin));
    }
};