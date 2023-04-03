class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        map<char,int> m,n;
        for(int i=0;i<s1.length();i++){
            m[s2[i]]++;
            n[s1[i]]++;
        }
        if(m==n) return true;
        for(int i=s1.length();i<s2.length();i++){
            m[s2[i]]++;
            m[s2[i-s1.length()]]--;
            int x=0;
            for(auto i:n){
                if(m[i.first]==i.second) ++x;
            }
            if(x==n.size()) return true;
        }
        return false;
    }
};