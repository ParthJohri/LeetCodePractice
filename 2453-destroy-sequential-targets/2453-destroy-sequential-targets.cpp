class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        long long ans=INT_MAX,mx=-1;
        map<long long ,long long > m,p;
        for(auto i:nums){
            m[i%space]++;
            if(!p.count(i%space))
            p[i%space]=i;
        }
        for(auto i:m){
            if(i.second>=mx){
                mx=i.second;
            }
        }
        for(auto i:m){
            if(i.second==mx){
                ans=min(ans,p[i.first]);
            }
        }
        return ans;
    }
};