class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m,n;
        unordered_map<char,char> q;
        unordered_map<int,int> p;
        for(int i=0;i<s.length();i++){
            if(q.count(s[i]) && q[s[i]]!=t[i])
                return false;
            q[s[i]]=t[i];
        }
        for(auto i:t){
            n[i]++;
        }
        for(auto i:s){
            m[i]++;
        }
        for(auto i:m){
            p[i.second]++;
        }
        for(auto i:n){
            p[i.second]--;
        }
        for(auto i:p){
            if(i.second!=0)
                return false;
        }
        return true;
    }
};