class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto i:tokens)
        {
            if(s.empty())
            s.push(i);
            if(i=="+")
            {
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();
                int c=a+b;
                s.push(to_string(c));
            }
            else if(i=="-")
            {
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();
                int c=b-a;
                s.push(to_string(c));
            }
            else if(i=="*")
            {
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();
                int c=b*a;
                s.push(to_string(c));
            }
            else if(i=="/")
            {
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();
                int c=b/a;
                s.push(to_string(c));
            }
            else
                s.push(i);
        }
        string v=s.top();
        int ans=stoi(v);
        return ans;
    }
};