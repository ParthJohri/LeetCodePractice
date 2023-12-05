class Solution {
public:
    string decodeString(string ns) {
        stack<string>st;
        string ans="",rev="",num="";
        vector<string> s;
        for(int i=0;i<ns.size();i++){
            if(isdigit(ns[i])){
                while(i<ns.size() and isdigit(ns[i])){
                    num+=ns[i++];
                }
                s.push_back(num);
                num="";
                i--;
            }
            else{
                s.push_back(string(1,ns[i]));
            }
        }
        for(auto i:s){
            cout<<i<<" ";
        }
        for(auto i:s){
            if(st.empty() or i!="]"){
                st.push(i);
            }
            else if(i=="]"){
                rev="";
                while(!st.empty() and st.top()!="["){
                    rev=st.top()+rev;
                    st.pop();
                }
                st.pop();
                int num=stoi(st.top());
                st.pop();
                string str="";
                for(int i=1;i<=num;i++){
                    str+=rev;
                }
                st.push(str);
            }
        }
        rev="";
        while(!st.empty()){
            rev=st.top()+rev;
            st.pop();
        }
        ans+=rev;
        return ans;
    }
};