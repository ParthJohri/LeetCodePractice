class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0, right = 0, sum =0, n=nums.size();
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                sum-=nums[left];
                ans = min(ans, right-left+1);
                left++;
            }
            right++;
        }
        return ans == INT_MAX?0:ans;
    }
};