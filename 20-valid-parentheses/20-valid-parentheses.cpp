class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        bool b=true;
        if(st.length()&1)
            b=false;
        for(auto i:st)
        {
            if(i=='('||i=='{'||i=='[')
                s.push(i);
            else if(!s.empty())
            {
                switch(i)
                    {
                    case '}':if(s.top()=='{')
                                s.pop();
                              else
                              b=false;
                                break;
                    case ')': if(s.top()=='(')
                                s.pop();
                        else
                              b=false;
                                break;
                    case ']': if(s.top()=='[')
                                s.pop();
                        else
                                  b=false;
                                break;
                }
            }
            else
                b=false;
        }
        if(s.size()>0)
            b=false;
        return b;
    }
};