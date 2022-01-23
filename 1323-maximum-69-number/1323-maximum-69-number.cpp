class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int count=s.length();
        for(int i=0;i<count;i++)
        {    char ch=s[i];
        if(ch=='6')
           {
         s[i]='9';
         break;}
        }
        return stoi(s);
    }
};