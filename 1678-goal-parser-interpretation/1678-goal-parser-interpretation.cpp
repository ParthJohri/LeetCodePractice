class Solution {
public:
    string interpret(string s) {
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('&&s[i+1]==')')
            {str+='o';
             i++;}
            else if(s[i]=='('&&s[i+1]=='a'&&s[i+2]=='l'&&s[i+3]==')')
               { str+="al";
               i=i+3;}
            else
                str+=s[i];
        }
        return str;
    }
};