class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string str;
        for(auto i:s){
            if(i=='*'){
                if(!st.empty())
                st.pop();
                continue;
            }
            st.push(i);
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};