class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            sub.push_back(sum);
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                sub.push_back(sum);
            }
        }
        sort(sub.begin(),sub.end());
        long long int ans=0,mod=1e9+7;
        int sz=sub.size(),start=max(0,left-1),end=min(sz-1,right-1);
        for(int i=start;i<=end;i++){
            ans=ans%mod+sub[i]%mod;
            ans%=mod;
        }
        return ans;
    }
};