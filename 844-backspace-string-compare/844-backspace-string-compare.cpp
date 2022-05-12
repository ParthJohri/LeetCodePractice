class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char> s1, s2;
       for(auto i:s)
       {
               if(i=='#'&&!s1.empty())
                   s1.pop();
               else if(i=='#'&&s2.empty())
                   continue;
               else
                   s1.push(i);
       }
        for(auto i:t)
       {
           if(i=='#'&&!s2.empty())
                   s2.pop();
            else if(i=='#'&&s2.empty())
                continue;
               else
                   s2.push(i);
       }
        string str1,str2;
        while(!s1.empty())
        {
            str1=s1.top()+str1;
            s1.pop();

        }
        while(!s2.empty())
        {
            str2=s2.top()+str2;
            s2.pop();
        }
        return str1==str2;
    }
};