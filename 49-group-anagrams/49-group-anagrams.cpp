class Solution {
public:
    bool checkAnagram(string &s,string &t)
    {
        if(s.length()!=t.length())
            return false;
        const int CHAR=256;
        int count[CHAR]={0};
        for(int i=0;i<s.length();i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }
        for(int i=0;i<CHAR;i++)
        {
            if(count[i]!=0)
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > v;
        vector<bool> b(strs.size());
        for(int i=0;i<strs.size();i++)
        {vector<string> row;
         if(!b[i])
         row.push_back(strs[i]);
            for(int j=i+1;j<strs.size();j++)
            {
                if(!b[j])
                {
                    if(checkAnagram(strs[i],strs[j]))
                        {b[j]=checkAnagram(strs[i],strs[j]);
                        row.push_back(strs[j]);}
                }
            }
         if(row.size()!=0)
         v.push_back(row);
         row.clear();
        }
        return v;
    }
};