class Solution {
public:
    string reverseWords(string s) {
        int p=0;
        s+=" ";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
                {
                reverse(p+s.begin(),i+s.begin());
                p=i+1;
                }
        }
        return s.substr(0,s.size()-1);
    }
};