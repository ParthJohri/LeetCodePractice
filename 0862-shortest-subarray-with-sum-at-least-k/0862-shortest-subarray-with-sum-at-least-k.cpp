#define ll long long

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ll ans=INT_MAX,n=nums.size(),s=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> p;
        for(ll i=0;i<n;i++){
            s+=nums[i];
            if(s>=k){
                ans=min(ans,i+1);
            }
            while(!p.empty() and s-p.top().first>=k){
                ans=min(ans,i-p.top().second);
                p.pop();
            }
            p.push({s,i});
        }
        return ans==INT_MAX?-1:ans;
    }
};