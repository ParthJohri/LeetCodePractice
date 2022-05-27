class Solution {
public:
    string reverseOnlyLetters(string s) {
        int x=0,y=s.length()-1;
        while(x<=y)
        {
            if(!isalpha(s[y]))
                {y--;
            continue;}
            if(!isalpha(s[x]))
            {
                x++;
                continue;
            }
            char c=s[x];
            s[x]=s[y];
            s[y]=c;
            x++;
            y--;
        }
        return s;
    }
};