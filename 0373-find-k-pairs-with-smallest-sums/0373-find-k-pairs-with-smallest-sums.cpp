#define pii pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pii> p;
        for(auto i:nums1){
            for(auto j:nums2){
                if(p.size()<k){
                    p.push({i+j,{i,j}});
                }
                else if(i+j<p.top().first){
                    p.pop();
                    p.push({i+j,{i,j}});
                }
                else break;
            }
        }
        while(!p.empty()){
            auto i=p.top().second.first,j=p.top().second.second;
            ans.push_back({i,j});
            p.pop();
        }
        return ans;
    }
};