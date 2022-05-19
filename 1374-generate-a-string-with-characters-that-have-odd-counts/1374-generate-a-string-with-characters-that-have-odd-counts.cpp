class Solution {
public:
    string generateTheString(int n) {
        string ans="";
        int num=n;
        if(n%2==0)
        {
            while(n---1>0)
            {
                ans+='a';
            }
            ans+='b';
        }
        else
        {
            while(num--)
            {
                ans+='a';
            }
        }
        return ans;
    }
};