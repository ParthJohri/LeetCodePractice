class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> m={
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };
        map<char,char> p={
            {')','('},
            {']','['},
            {'}','{'}
        };
        for(auto i:s){
            if(m.count(i)){
                st.push(i);
            }else {
                if(st.empty() or st.top()!=p[i]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};