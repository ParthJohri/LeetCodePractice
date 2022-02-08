class Solution {
public:
    int ascii(string &s)
    {
        int val=0;
        for(auto i:s)
        {
            val+=i-'0';
        }
        return val;
    }
    string rmzeros( string &str)
    {
        string nstr="";
        if(str=="0"||ascii(str)==0)
            return "0";
        else if(str[0]!='0')
            return str;
        else
        {int pos=0;
            for(int i=0;i<str.length();i++)
            {
                if(str[i]!='0')
                {pos=i;
                 break;}
            }
                nstr=str.substr(pos,str.length());
        }
        return nstr;
    }
    int numDifferentIntegers(string word) {
        for(int i=0;i<word.length();i++)
        {
            if(isalpha(word[i]))
                word[i]=' ';
        }
        word+=' ';
        unordered_set<string> s;
        string temp="";
        
        for(auto i: word)
        {
            if(i!=' ')
                temp+=i;
            else
                {cout<<temp<<" ";
                if(temp!="")
                s.insert(rmzeros(temp));
                temp="";}
        }
        return s.size();
    }
};