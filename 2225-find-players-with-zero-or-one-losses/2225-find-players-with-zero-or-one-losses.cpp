class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> m,n;
        for(auto i:matches){
            n[i[0]]++;
            m[i[1]]++;
            if(n.count(i[1])) n.erase(i[1]);
        }
        for(auto i:m){
            if(n.count(i.first)) n.erase(i.first);
        }
        for(auto i:n){
             ans[0].push_back(i.first);
        }
        for(auto i:m){
            if(i.second==1){
                ans[1].push_back(i.first);
            }
        }
        return ans;
    }
};