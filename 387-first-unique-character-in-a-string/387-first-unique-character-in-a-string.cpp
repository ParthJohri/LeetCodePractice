class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;
        int v=INT_MAX;
        bool b=false;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]].first=i;
            m[s[i]].second++;
        }
        for(auto i:m)
        {
            if(i.second.second==1&&i.second.first<=v)
                {b=true;v=i.second.first;}
        }
        return b?v:-1;
    }
};