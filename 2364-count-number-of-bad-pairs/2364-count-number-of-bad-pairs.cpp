class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0,n=nums.size(),goodpairs=0;
        unordered_map<long long,long long> m;
        for(int i=0;i<n;i++){
            goodpairs+=m[i-nums[i]]++;
        }
        ans=n*(n-1)/2;
        ans-=goodpairs;
        return ans;
    }
};