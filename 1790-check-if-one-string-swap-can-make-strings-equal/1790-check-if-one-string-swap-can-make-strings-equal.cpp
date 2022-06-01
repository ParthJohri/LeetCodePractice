class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        if(s1==s2) return true;
        
        if(s1.length()!=s2.length()) return false;
        
        int count=0;
        
        vector<char> v;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
                {
                    v.push_back(s1[i]);
                    v.push_back(s2[i]);
                    count++;
                }
        }
        return count==2 && v[0]==v[3] && v[1]==v[2];
    }
};