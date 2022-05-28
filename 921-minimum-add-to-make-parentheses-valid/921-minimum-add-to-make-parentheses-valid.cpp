class Solution {
public:
    int minAddToMakeValid(string s) {
        // Time Complexity : O(N)
        // Space Complexity: O(N)
        int not_closed=0,not_opened=0;
        for(auto i:s)
        {
            if(i=='(')
                not_closed++;
            else if(i==')' && not_closed>0)
                not_closed--;
            else
                not_opened++;
        }
        return not_closed+not_opened;
        // Time Complexity: O(N);
        // Space Complexity: O(N);
        // stack<char> st;
        // int count=0;
        // for(auto i:s)
        // {
        //     if(st.empty()&&i!=')')
        //         st.push('(');
        //     else if(st.empty()&&i==')')
        //        ++count;
        //     else if(i=='(')
        //         st.push('(');
        //     else if(st.top()=='('&&i==')')
        //         st.pop();
        //     else
        //         ++count;
        // }
        // return count+st.size();
    }
};