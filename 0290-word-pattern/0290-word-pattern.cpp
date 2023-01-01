class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char> m;
        map<char,int> n;
        s+=" ";
        string w="",ans="",pat="";
        int l=pattern.length();
        vector<string> v;
        for(auto i:s){
            if(i==' '){
                v.push_back(w);
                w="";
            }
            else{
                w+=i;
            }
        }
        char ch='a';
        for(int i=0;i<l;i++){
            if(!m.count(v[i])) m[v[i]]=ch++;
        }
        for(auto i:v){
            ans+=m[i];
        }
        ch='a';
        for(auto i:pattern){
            if(!n.count(i)) n[i]=ch++;
        }
        for(auto i:pattern){
            pat+=n[i];
        }
        return pat==ans;
    }
};