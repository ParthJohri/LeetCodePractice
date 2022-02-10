class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> n;
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]=='\0')
            m[s[i]]=t[i];
        }
        for(int i=0;i<t.length();i++)
        {
            if(n[t[i]]=='\0')
            n[t[i]]=s[i];
        }
        string str="",nstr="";
        for(auto i:s)
        {
            str+=m[i];
        }
        for(auto i:t)
        {
            nstr+=n[i];
        }
        return str==t&&nstr==s;
    }
};