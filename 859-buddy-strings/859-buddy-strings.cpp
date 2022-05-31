class Solution {
public:
    bool buddyStrings(string s, string goal) {
        map<char,int> m,m1;
        for(auto i:s)
                    m[i]++;
        if(s.length()==goal.length())
        {
            if(s!=goal)
            {
                int swaps=0;
                for(int i=0;i<s.length();i++)
                   {
                        if(s[i]!=goal[i])
                            ++swaps;
                   }
                if(swaps>2)
                    return false;
                for(auto i:goal)
                   {
                        m1[i]++;
                   }
                for(auto i:m)
                   {
                        if(i.second!=m1[i.first])
                            return false;
                   }
                return true;
            }
            else
            {
                int c=0;
                for(auto i:m)
                   {
                        if(i.second==1)
                            ++c;
                   }
                return c!=goal.length();
            }
        }
        return false;
    }
};