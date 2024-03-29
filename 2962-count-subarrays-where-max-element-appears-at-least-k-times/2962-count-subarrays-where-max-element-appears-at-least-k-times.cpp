class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int i=0,j=0,n=nums.size(),mx=*max_element(nums.begin(),nums.end()),count=0;
        while(j<n){
            if(nums[j]==mx) ++count;
            while(count>=k and i<=j){
                if(nums[i++]==mx) --count;
                ans+=(n-j);
            }
            j++;
        }
        return ans;
    }
};