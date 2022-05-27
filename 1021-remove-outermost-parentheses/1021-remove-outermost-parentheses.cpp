class Solution {
public:
    string removeOuterParentheses(string str) {
        string ans="";
        int count=0;
        stack<char> s;
        for(auto i:str)
        {
            if(s.empty())
                s.push(i);
            else if(s.top()=='('&&i=='(')
                {
                    ans+=i;
                    count++;
                }
             else if(count==0)
                s.pop();
            else if(i==')')
                {
                    ans+=i;
                    count--;
                }
        }
        return ans;
    }
};