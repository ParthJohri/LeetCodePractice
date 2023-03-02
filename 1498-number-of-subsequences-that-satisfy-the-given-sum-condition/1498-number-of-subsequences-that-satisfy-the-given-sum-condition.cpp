class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long int ans=0,mod=1e9+7,n=nums.size();
        long long int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=(dp[i-1]%mod*2%mod)%mod;
        }
        int i=0,j=nums.size()-1;
        while(i<nums.size() and j>0 and i<=j){
            if(nums[i]+nums[j]>target){
            j--;
        }
        else{
            int l=j-i;
            ans+=(dp[l])%mod;
            i++;
            }
        }
        return ans%mod;
    }
};