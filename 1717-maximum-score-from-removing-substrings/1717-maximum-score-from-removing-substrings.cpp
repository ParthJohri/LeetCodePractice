class Solution {
public:
    int maximumGain(string s, int x, int y) {
        bool b=x>y;
        int ans=0;
        stack<char> st;
        if(b){
            for(auto i:s){
                if(st.empty())
                  {  st.push(i);continue;}
                else if(st.top()=='a'&&i=='b'){
                    st.pop();
                    ans+=x;
                }
                else 
                    st.push(i);
            }
            s="";
            while(!st.empty()){
            s+=st.top();
            st.pop();}
            reverse(s.begin(),s.end());
            for(auto i:s){
                if(st.empty())
                   { st.push(i);continue;}
                else if(st.top()=='b'&&i=='a'){
                    st.pop();
                    ans+=y;
                }
                else
                    st.push(i);
            }
        }
        else{
            for(auto i:s){
                if(st.empty())
                   { st.push(i);continue;}
                else if(st.top()=='b'&&i=='a'){
                    st.pop();
                    ans+=y;
                }
                else
                    st.push(i);
            }
            s="";
            while(!st.empty()){
            s+=st.top();
            st.pop();}
            reverse(s.begin(),s.end());
            for(auto i:s){
                if(st.empty())
                  {  st.push(i);continue;}
                else if(st.top()=='a'&&i=='b'){
                    st.pop();
                    ans+=x;
                }
                else 
                    st.push(i);
            }
        }
        return ans;
    }
};