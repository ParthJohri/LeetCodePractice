class Solution {
public:
    int helper(string &s,int x, int y, char x1,char y1){
        int ans=0;
        stack<char> st;
        for(auto i:s){
                if(st.empty())
                  {  st.push(i);continue;}
                else if(st.top()==x1&&i==y1){
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
                else if(st.top()==y1&&i==x1){
                    st.pop();
                    ans+=y;
                }
                else
                    st.push(i);
            }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        bool b=x>y;
        if(b){
            return helper(s,x,y,'a','b');
        }
        else{
            return helper(s,y,x,'b','a');
        }
        return 0;
    }
};