class Solution {
public:
    int atMostSubArrays(vector<int> &nums,int goal) {
        int i=0,j=0,n=nums.size(),count=0,s=0;
        if(goal<0) return 0;
        while(j<n) {
            s+=nums[j];;
            while(s>goal) {
                s-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostSubArrays(nums,goal)-atMostSubArrays(nums,goal-1);
    }
};