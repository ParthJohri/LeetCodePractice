class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> q,b;
        if(s==t) return true;
        for(int i=0;i<s.length();i++){
            if(q.count(s[i]) && q[s[i]]!=t[i] || !q.count(s[i]) && b.count(t[i]))
                return false;
            q[s[i]]=t[i];
            b[t[i]]=s[i];
        }
        for(int i=0;i<s.length();i++){
            s[i]=q[s[i]];
        }
        return s==t;
    }
};