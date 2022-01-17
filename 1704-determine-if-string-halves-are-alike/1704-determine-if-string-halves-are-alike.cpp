class Solution {
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string a=s.substr(0,s.length()/2);
        string b=s.substr(s.length()/2,s.length()/2);
        int ca=0,cb=0;
        for(auto i:a)
            {if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')
                ++ca;}
        for(auto i:b)
        {
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')
                ++cb;
        }
        return ca==cb;
    }
};