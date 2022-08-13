class Solution {
public:
    string removeOccurrences(string s, string part) {
        for(int i=0;i<s.length();i++){
            if(s[i]==part[0]){
                string t=s.substr(i,part.length());
                if(t==part){
                    cout<<"t "<<t<<endl;
                    string str=s;
                    s=str.substr(0,i)+str.substr(i+part.length());
                    cout<<"s "<<s<<endl;
                    i=-1;
                }
            }
        }
        return s;
    }
};