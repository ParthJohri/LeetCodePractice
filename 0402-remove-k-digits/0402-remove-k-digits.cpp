class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==1&&k==1) return "0";
        stack<char> st;
        for(auto i:num){
            if(st.empty()){
            st.push(i);
            continue;
            }
            while (!st.empty()&&st.top()>i&&k){
                --k;
                st.pop();
            }
            st.push(i);
        }
        while(k&&!st.empty()){
            --k;
            st.pop();
        }
        num="";
        while(!st.empty()){
            num+=st.top();
            st.pop();
        }
        reverse(num.begin(),num.end());
        if(k){
            num=num.substr(k);
        }
        if(num[0]=='0'&&num.size()>1){
            int x=0;
            while(num[x]=='0'){
                x++;
            }
            num=num.substr(x);
            return num.size()?num:"0";
        }
        return num.size()?num:"0";
    }
};