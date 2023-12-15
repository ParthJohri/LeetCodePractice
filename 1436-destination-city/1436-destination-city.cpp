class Solution {
public:
    map<string,vector<string>> m;
    string dfs(string city){
        string ans = city;
        for(auto j:m[city]){
           ans = dfs(j);
        }
        return ans;
    }
    string destCity(vector<vector<string>>& paths) {
        string ans="";
        set<string> s;
        for(auto i:paths){
            m[i[0]].push_back(i[1]);
            s.insert(i[0]);
            s.insert(i[1]);
        }
        for(auto i:s){
            ans=dfs(i);
        }
        return ans;
    }
};