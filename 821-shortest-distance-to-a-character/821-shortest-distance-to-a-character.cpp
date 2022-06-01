class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> pos,ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==c)
                pos.push_back(i);
        }
        int x=0,temp=0;
        for(int i=0;i<s.length();i++)
        {
            if(i==pos[x] && x!=pos.size()-1)
               {
                    ans.push_back(0);
                    temp=x;
                    x++;
               }
            else 
                {
                    int v=min(abs(pos[x]-i),abs(pos[temp]-i));
                    ans.push_back(v);
                }
        }
        return ans;
    }
};