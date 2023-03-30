class Solution {
public:
    unordered_map<string,bool> m;
    bool isScramble(string s1, string s2) {
        int n=s1.length();
        string s=s1+" "+s2;
        if(s1==s2) return true;
        if(n==1) return false;
        if(m.count(s)) return m[s];
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i),s2.substr(i))) return m[s]=true;
            if(isScramble(s1.substr(0,i),s2.substr(n-i)) and isScramble(s1.substr(i),s2.substr(0,n-i))) return m[s]=true;
        }
        return m[s]=false;
    }
};