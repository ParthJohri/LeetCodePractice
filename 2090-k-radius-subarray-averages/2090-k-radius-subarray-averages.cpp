class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        long long n=nums.size(),start=k,end=n-1+k,sum=0;
        if(2*k+1>n) return ans;
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
        }
        long long div=2*k+1;
        ans[start++]=sum/div;
        for(long long i=2*k+1;i<n;i++){
            sum+=nums[i]-nums[i-2*k-1];
            ans[start++]=sum/div;
        }
        return ans;
    }
};