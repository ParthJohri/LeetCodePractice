class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {  
            if(st.empty())
                st.push(s[i]);
            else if(s[i]!=st.top())
                st.push(s[i]);
            else
                st.pop();
        }
        while(!st.empty())
        {ans+=st.top();
         st.pop();}
         reverse(ans.begin(),ans.end());
        return ans;
    }
};