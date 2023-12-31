class Solution {
public:
    bool check(string s,int len,unordered_map<string,int> m){
        for(int j=0;j<s.size();j+=len){
            string str=s.substr(j,len);
            if(m.count(str)){
                if(--m[str]==-1) return false;
            }
            else return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int>m;
        
        for(auto i:words) m[i]++;
        int len=words[0].size();
        int stringlength=len*words.size();
        int l=s.size()-stringlength;
        for(int i=0;i<=l;i++){
            if(check(s.substr(i,stringlength),len,m)) ans.push_back(i);
        }
        return ans;
    }
};