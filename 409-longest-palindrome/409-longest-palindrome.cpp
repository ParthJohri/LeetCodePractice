class Solution {
public:
    int longestPalindrome(string s) {
        const int CHAR=256;
        int count[CHAR]={0};
        for(auto i: s)
            count[i]++;
        int len=0,element=0;
        bool b=false;
        for(int i=0;i<CHAR;i++)
        {
            if((count[i]&1)==0)
                {len+=count[i];
                 }
            else
                {len+=count[i]-1;
                b=true;
                if(count[i]==s.length())
                ++element;}
        }
        if(element==1)
            return s.length();
        return b?len+1:len;
    }
};