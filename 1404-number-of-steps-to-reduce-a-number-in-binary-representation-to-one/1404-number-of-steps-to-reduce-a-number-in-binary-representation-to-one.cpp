class Solution {
public:
    void add(string &s)
    {
        int n=s.length();
        string ad="";
        while(--n)
        {
            ad+="0";
        }
        ad+="1";
        bool b=false;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='1'&&ad[i]=='1')
               { 
                 s[i]='0';
                 b=true;
               }
            else if(b)
            {
                if(s[i]=='1' &&ad[i]=='0')
                    {
                        s[i]='0';
                        b=true;
                    }
                else if(s[i]=='1'&&ad[i]=='1')
                    {
                        s[i]='1';
                        b=true;
                    }
                else
                    {
                        s[i]='1';
                        b=false;
                    }
            }
            else if(s[i]=='0'&&ad[i]=='0')
                s[i]='0';
            else
                s[i]='1';
        }
        if(b)
            s="1"+s;
    }
    int numSteps(string s) {
        int count=0;
        while(s!="1")
        {
            if(s[s.length()-1]=='1')
            {
                add(s);
            }
            else if(s[s.length()-1]=='0')
                s=s.substr(0,s.length()-1);
            count++;
        }
        return count;
    }
};