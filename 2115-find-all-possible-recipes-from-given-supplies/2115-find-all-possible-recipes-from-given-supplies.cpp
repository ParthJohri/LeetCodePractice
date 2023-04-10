class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        map<string,vector<string>> m;
        map<string,int> indegree;
        map<string,int> s;
        queue<string> q;
        for(auto i:supplies){
            s[i]++;
        }
        for(auto i:recipes){
            indegree[i]=0;
        }
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(s[ingredients[i][j]]==0){
                    m[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        for(auto i:indegree){
            if(i.second==0) q.push(i.first);
        }
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto i:m[curr]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i); 
            }
        }
        return ans;
    }
};