class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> p;
        for(auto i:nums) m[i]++;
        for(auto i:m)
        {
            p.push({i.second,i.first});
        }
        while(k!=0)
        {
            pair<int,int> pr=p.top();
            v.push_back(pr.second);
            p.pop();
            k--;
        }
        return v;
    }
};