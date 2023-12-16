class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(t.length()!=s.length()) return false;
        int i=0,j=0;
        while(i<s.length() and j<t.length()){
            if(s[i]!=t[j]) return false;
            i++;
            j++;
        }
        return true;
    }
};