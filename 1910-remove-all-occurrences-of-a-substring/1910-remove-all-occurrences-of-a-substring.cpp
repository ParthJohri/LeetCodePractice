class Solution {
public:
    string removeOccurrences(string s, string part) {
        for(int i=0;i<s.length();i++){
            if(s[i]==part[0]){
                string t=s.substr(i,part.length());
                if(t==part){
                    string str=s;
                    s=s.substr(0,i)+s.substr(i+part.length());
                    i=-1;
                }
            }
        }
        return s;
    }
};