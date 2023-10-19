class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b="";
        int c=0,d=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#') ++c;
            else {
                c--;
                if(c<0) {
                    a+=s[i];
                    c=0;
                }
            }
        }
        for(int j=t.length()-1;j>=0;j--){
            if(t[j]=='#') ++d;
            else {
                d--;
                if(d<0) {
                    b+=t[j];
                    d=0;
                }
            }
        }
        cout<<a<<endl;
        cout<<b<<endl;
        return a==b;   
    }
};