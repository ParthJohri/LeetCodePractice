class Solution {
public:
    void dfs(int i,vector<string>&strs,vector<bool>&vis){
        vis[i]=true;
        for(int j=0;j<strs.size();j++){
            if(vis[j]) continue;
            if(anagram(strs[i],strs[j]))
                dfs(j,strs,vis);
        }
    }
    bool anagram(string&s, string&t){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]) ++count;
        }
        return count==2 or count==0;
    }
    int numSimilarGroups(vector<string>& strs) {
        int groups=0;
        vector<bool> vis(strs.size(),false);
        for(int i=0;i<strs.size();i++){
            if(vis[i]) continue;
            dfs(i,strs,vis);
            groups++;
        }
        return groups;
    }
};