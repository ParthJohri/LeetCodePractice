class Solution {
private:
    set<string> s;
public:
    string flip(int type,string& s){
        if(type==0){
            for(int i = 0;i<s.length();i++){
                if(s[i]=='1') s[i]='0';
                else s[i]='1';
            }
        }
        else if(type==1){
            for(int i = 1;i<s.length();i+=2){
                if(s[i]=='1') s[i]='0';
                else s[i]='1';
            }
        }
        else if(type==2){
            for(int i = 0;i<s.length();i+=2){
                if(s[i]=='1') s[i]='0';
                else s[i]='1';
            }
        }
        else{
            for(int k = 0;3*k+1<=s.length();k++){
                int i = 3*k;
                if(s[i]=='1') s[i]='0';
                else s[i]='1';
            }
        }
        return s;
    }
    void recur(string& str,int presses,unordered_map<string,unordered_map<int,int>>&m){
        if(presses==0){
            s.insert(str);
            return;
        }
        if(m.count(str) and m[str].count(presses)) return;
        m[str][presses]=1;
        string ans=flip(0,str);
        recur(ans,presses-1,m);
        ans=flip(1,str);
        recur(ans,presses-1,m);
        ans=flip(2,str);
        recur(ans,presses-1,m);
        ans=flip(3,str);
        recur(ans,presses-1,m);
    }
    int flipLights(int n, int presses) {
        unordered_map<string,unordered_map<int,int>> m;
        string str(n,'1');
        recur(str,presses,m);
        return s.size();
    }
};