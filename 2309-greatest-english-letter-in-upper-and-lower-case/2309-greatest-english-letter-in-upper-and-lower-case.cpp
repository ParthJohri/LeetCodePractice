class Solution {
public:
    string greatestLetter(string s) {
        string ans="",finalans="";
        for(char c='A';c<='Z';c++)
        {
            for(auto i:s)
            {
                if(i==c) {ans+=c; break;}
            }       
        }
        cout<<ans;
        for(int i=ans.size()-1;i>=0;i--)
        {
            for(auto j:s)
            {
                if(tolower(ans[i])==j)
                return finalans+=ans[i];
            }
        }
        return finalans;
    }
};