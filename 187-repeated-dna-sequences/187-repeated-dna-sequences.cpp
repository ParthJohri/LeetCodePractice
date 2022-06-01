class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        
        if(s.length()<10)
            return v;
                
        unordered_map<string,int> m;

        for(int i=0;i<s.length()-9;i++)
        {
            m[s.substr(i,10)]++;
        }
        
            for(auto i: m)
                {
                    if(i.second>1)
                        v.push_back(i.first);
                }
        
        return v;
    }
};