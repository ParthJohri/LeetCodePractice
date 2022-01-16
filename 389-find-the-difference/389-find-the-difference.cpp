class Solution {
public:
    char findTheDifference(string s, string t) {
        char m=0;
        for(char n:s)
            m^=n;
        for(char o:t)
            m^=o;
        return m;
    }
};