class Solution {
public:
    vector<string> cellsInRange(string s) {
        char sc=s[0],ec=s[3],sn=s[1],en=s[4];
        vector<string> ans;
        for(char c=sc;c<=ec;c++)
          { 
            for(char i=sn;i<=en;i++)
            {
                string temp="";
                temp+=c;
                temp+=i;
                ans.push_back(temp);
            }
           }
        return ans;
    }
};