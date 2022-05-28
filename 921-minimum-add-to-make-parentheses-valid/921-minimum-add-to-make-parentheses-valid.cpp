class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(auto i:s)
        {
            if(st.empty()&&i!=')')
                st.push('(');
            else if(st.empty()&&i==')')
               ++count;
            else if(i=='(')
                st.push('(');
            else if(st.top()=='('&&i==')')
                st.pop();
            else
                ++count;
        }
        return count+st.size();
    }
};