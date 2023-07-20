class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,sum=0;
        int i=0,j=0,n=nums.size();
        while(j<n){
            long long len=j-i+1;
            sum+=nums[j];
            while(i<n and sum*len>=k){
                sum-=nums[i];
                ++i;
                len=j-i+1;
            }
            ans+=j-i+1;   
            j++;
        }
        return ans;
    }
};