class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<long long,long long>> ans;
        for(long long i=0;i<nums.size();i++){
            ans.push_back({nums[i],cost[i]});
        }
        sort(ans.begin(),ans.end());
        long long mx=*max_element(nums.begin(),nums.end());
        long long l=1,h=mx,fans=LLONG_MAX,n=nums.size();
        while(l<=h){
            long long mid=l+(h-l)/2,cc=0,m=mid+1,c=0;
            for(int i=0;i<n;i++){
                long long val=abs(ans[i].first-mid);
                cc+=val*1ll*ans[i].second;
                val=abs(ans[i].first-m);
                c+=val*1ll*ans[i].second;
            }
            fans=min({fans,cc,c});
            if(c>=cc){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return fans;
    }
};