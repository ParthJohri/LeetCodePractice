class Solution {
public:
    int rev(int n){
        int r=0;
        while(n!=0){
            r=r*10+(n%10);
            n=n/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        long long mod=1e9+7,ans=0;
        unordered_map<long long,long long> m;
        for(auto i:nums){
            int r=rev(i);
            ans+=m[i-r]%mod;
            m[i-r]++;
        }
        return ans%mod;
    }
};