class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> s;
        for(auto i:logs)
        {
            s[i[0]].insert(i[1]);
        }
        vector<int> v(k,0);
        for(auto i:s)
        {
            v[i.second.size()-1]++;
        }
        return v;
    }
};