class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> ans;
        vector<int> topKElements;
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            ans.push_back({i.first,i.second});
        }
        sort(ans.begin(),ans.end(),[](pair<int,int>&a,pair<int,int>&b)->bool{
            return a.second>=b.second;
        });
        int i=0;
        while(k-- && i<ans.size()){
            topKElements.push_back(ans[i].first);
            i++;
        }
        return topKElements;
    }
};