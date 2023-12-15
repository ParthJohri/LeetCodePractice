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
        for(auto i:paths){
            m[i[0]].push_back(i[1]);
        }
        ans = dfs(paths[0][0]);
        return ans;
    }
};