class Solution {
public:
    int calPoints(vector<string>& ops) {
       int ans=0;
        stack<string> s;
        for(auto i:ops)
        {
            s.push(i);
            if(i=="C")
            {
                s.pop();
                s.pop();
            }
            else if(i=="D")
            {
                s.pop();
                s.push(to_string(2*stoi(s.top())));
            }
            else if(i=="+")
            {
                s.pop();
                string s1=s.top();
                s.pop();
                string sum=to_string(stoi(s1)+stoi(s.top()));
                s.push(s1);
                s.push(sum);
            }
        }
        while(!s.empty())
        {
            ans+=stoi(s.top());
            s.pop();
        }
        return ans;
    }
};