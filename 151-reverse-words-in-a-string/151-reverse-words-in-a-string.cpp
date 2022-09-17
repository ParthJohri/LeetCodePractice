class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp="";
        s+=" ";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' and s[i+1]==' '){
                continue;
            }
            else if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                ans=temp+" "+ans;
                temp="";
            }
        }
        int i=0;
        for(i=ans.length()-1;i>=0;i--){
            if(ans[i]!=' ')
                break;
        }
        return ans.substr(0,i+1);
    }
};