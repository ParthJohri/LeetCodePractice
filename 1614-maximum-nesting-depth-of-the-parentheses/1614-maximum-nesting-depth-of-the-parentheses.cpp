class Solution {
public:
    int maxDepth(string st) {
        stack<char> s;
        int count=0,mx=0;
        for(auto i:st)
        {
            if(i=='(')
                {
                    s.push('(');
                        ++count;
                    if(count>=mx)
                         mx=count;
                }
            else if(i==')')
                {
                    s.pop();
                    count--;
                }
        }
        return mx;
    }
};