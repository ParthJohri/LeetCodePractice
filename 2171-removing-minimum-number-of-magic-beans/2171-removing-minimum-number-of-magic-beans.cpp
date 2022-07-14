class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end(),greater<int>());
        long long ans=LLONG_MAX,total=accumulate(beans.begin(),beans.end(),0ll);
        for(int i=0;i<beans.size();i++){
            ans=min(ans,total-(beans[i]*1ll*(i+1)));
        }
        return ans;
    }
};