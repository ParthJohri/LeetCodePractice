class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        if(s.length()<10)
            return ans;
        
        s+="          ";
        
        for(int i=0;i<s.length()-10;i++)
        {
            ans.push_back(s.substr(i,10));
        }
        
        map<string,int> m;
        for(auto i:ans)
        {
            m[i]++;
        }
        
        vector<string> v;
        if(m.size()==1)
            {
                for(auto i: m)
                    {
                            v.push_back(i.first);
                    }
            }
        else
        {
            for(auto i: m)
                {
                    if(i.second>1)
                        v.push_back(i.first);
                }
        }
        return v;
    }
};