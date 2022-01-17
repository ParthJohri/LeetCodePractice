class Solution {
public:
    bool halvesAreAlike(string s) {
        string a=s.substr(0,s.length()/2);
        string b=s.substr(s.length()/2,s.length()/2);
        int ca=0,cb=0;
        for(auto i:a)
            {if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='A'||i=='E'||i=='I'||i=='O'||i=='U')
                ++ca;}
        for(auto i:b)
        {
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='A'||i=='E'||i=='I'||i=='O'||i=='U')
                ++cb;
        }
        return ca==cb;
    }
};