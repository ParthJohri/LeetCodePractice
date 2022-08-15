class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' '){
            i++;
        }
        bool pos=true;
        if(s[i]=='-'||s[i]=='+'){
            if(s[i]=='-')
            pos=false;
            i++;
        }
        int ans=0;
        while(s[i]>='0' and s[i]<='9'){
            if(ans>INT_MAX/10 || ans==INT_MAX/10 and s[i]-'0'>7){
                return pos?INT_MAX:INT_MIN;
            }
            ans=ans*10+(s[i]-'0');
            i++;
        }
        return pos?ans:ans*-1;
    }
};