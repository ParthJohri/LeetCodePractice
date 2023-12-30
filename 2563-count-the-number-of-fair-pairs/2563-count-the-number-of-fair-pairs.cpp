class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        int id=0;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            int l=lower-i;
            int u=upper-i;
            int ld=lower_bound(nums.begin(),nums.end(),l)-nums.begin();
            if(ld<=id) ld=id+1;
            int ud=upper_bound(nums.begin(),nums.end(),u)-nums.begin();
            if(ud>ld)
                ans+=ud-ld;
            id++;
            cout<<id<<" "<<ld<<" "<<ud<<endl;
        }
        return ans;
    }
};