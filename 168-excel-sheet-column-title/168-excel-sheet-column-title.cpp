class Solution {
public:
    string convertToTitle(int n) {
    string ans="";
        while(n--)
        {
            ans=char(n%26+'A')+ans;
            n/=26;
        }
        return ans;
    }
};