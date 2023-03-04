class Solution {
public:
    int atmostKOdds(vector<int>&nums,int k){
        int count =0,start=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) count++;
            while(count > k) {
                if(nums[start]%2) {
                    count--;
                }
                start++;
            }
            ans+=i-start+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        long long count=0,odd=0,i=0,j=0;
        // 1 2 2 3 4
        // 4 3 2 2 1
        return count=atmostKOdds(nums,k)-atmostKOdds(nums,k-1);
    }
};