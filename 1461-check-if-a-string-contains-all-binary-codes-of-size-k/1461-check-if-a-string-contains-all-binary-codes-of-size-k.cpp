class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        int count=0;
        if(s.length()<k)
            return false;
        for(int i=0;i<=s.length()-k;i++)
        {
            string str=s.substr(i,k);
            st.insert(str);
        }
        return st.size()==1<<k;
    }
};