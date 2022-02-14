class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int m=word1.length();
        int n=word2.length();
        int x=0;
        int y=0;
        while(x<m||y<n)
        {
            if(x<m)
            s+=word1[x++];
            if(y<n)
            s+=word2[y++];
        }
        return s;
    }
};