class Solution {
public:
    string convertToTitle(int n) {
    string ans="";
        while(n--) // Important check the discuss section since excel stores it in a 1 to 26 system and not in 0 to 25 system
        {
            ans=char(n%26+'A')+ans;
            n/=26;
        }
        return ans;
    }
};