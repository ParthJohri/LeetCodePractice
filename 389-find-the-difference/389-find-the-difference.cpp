class Solution {
public:
    char findTheDifference(string s, string t) {
        int m=0;
        for(int i=0;i<s.length();i++)
        {
            int one=(int)s[i];
            m^=one;
        }
        for(int i=0;i<t.length();i++)
        {
            int two=(int)t[i];
            m^=two;
        }
        return (char)m;
    }
};