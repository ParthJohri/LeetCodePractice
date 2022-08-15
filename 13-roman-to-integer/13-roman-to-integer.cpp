class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m={
            {'M',1000},
            {'D',500},
            {'C',100},
            {'L',50},
            {'X',10},
            {'V',5},
            {'I',1}
        };
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans+=4;++i;}
                else if(s[i+1]=='X'){
                    ans+=9;++i;}
                else 
                    ans+=m[s[i]];
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans+=40;
                ++i;}
                else if(s[i+1]=='C'){
                    ans+=90;
                ++i;}
                else
                    ans+=m[s[i]];
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ans+=400;++i;}
                else if(s[i+1]=='M'){
                    ans+=900;++i;}
                else
                    ans+=m[s[i]];
            }
            else
            ans+=m[s[i]];
        }
        return ans;
    }
};