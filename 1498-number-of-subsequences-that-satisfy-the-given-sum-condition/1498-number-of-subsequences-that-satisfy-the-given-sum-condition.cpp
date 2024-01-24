class Solution {
public:
    long long int power(long long int base,long long int exp,int mod){
        long long int ans=1;
        while(exp){
            if(exp%2){
                ans=(ans%mod*1ll*base%mod)%mod;
            }
            base=(base%mod*base%mod)%mod;
            exp>>=1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long int ans=0,mod=1e9+7,left=0,right=nums.size()-1;
        while(left<=right){
            if(nums[left]+nums[right]>target) right--;
            else if(nums[left]+nums[right]<=target){
                long long int dist=right-left;
                long long int val=power(2,dist,mod);
                ans=(ans%mod+val%mod)%mod;
                left++;
            }
        }
        return ans;
    }
};