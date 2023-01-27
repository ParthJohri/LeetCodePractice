class Solution {
public:
    unordered_map<string,bool> dp;
    bool check(string& words,unordered_set<string>&s){
        if(dp.find(words)!=dp.end()) return dp[words];
       for(int i=0;i<words.length();i++){
                string pr=words.substr(0,i+1);
                string su=words.substr(i+1);
                if(s.find(pr)!=s.end() and s.find(su)!=s.end() or s.find(pr)!=s.end() and check(su,s)){
                return dp[words]=true;
                }
        }
        return dp[words]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s;
        dp.clear();
        vector<string> ans;
        for(auto i:words){
            s.insert(i);
        }
        for(auto i:words){
            if(check(i,s)) ans.push_back(i);
        }
        return ans;
    }
};