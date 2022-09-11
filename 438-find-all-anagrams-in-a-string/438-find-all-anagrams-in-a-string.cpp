class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m,t;
        vector<int> ans;
        int pos=0;
        if(p.length()>s.length()) return ans;
        for(auto i='a';i<='z';i++){
            m[i]=t[i]=0;
        }
        for(auto i:p){
            t[i]++;
        }
        for(int i=0;i<p.length();i++){
            m[s[i]]++;
        }
        if(m==t) ans.push_back(pos);
        for(int i=p.length();i<s.length();i++){
            m[s[i-p.length()]]--;
            m[s[i]]++;
            pos++;
            if(m==t) ans.push_back(pos);
        }
        return ans;
    }
};