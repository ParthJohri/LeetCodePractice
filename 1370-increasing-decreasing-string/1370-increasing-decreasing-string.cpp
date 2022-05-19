class Solution {
public:
    string sortString(string s) {
        vector<int> m(26,0);
        string ans="";
        for(auto i:s)
            {m[i-'a']++;}
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<m.size();j++)
            {
                if(m[j]>0)
                {
                    ans+=j+'a';
                    m[j]--;
                }
            }
            for(int k=m.size()-1;k>=0;k--)
            {
                if(m[k]>0)
                {
                    ans+=k+'a';
                    m[k]--;
                }
            }
        }
        return ans;
    }
};