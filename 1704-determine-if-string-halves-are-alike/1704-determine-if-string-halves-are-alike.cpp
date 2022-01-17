class Solution {
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        unordered_set<char> v={'a','e','i','o','u'};
        string a=s.substr(0,s.length()/2);
        string b=s.substr(s.length()/2,s.length()/2);
        int ca=0,cb=0;
        for(auto i:a)
            {if(v.find(i)!=v.end())
                ++ca;}
        for(auto i:b)
        {
            if(v.find(i)!=v.end())
                ++cb;
        }
        return ca==cb;
    }
};