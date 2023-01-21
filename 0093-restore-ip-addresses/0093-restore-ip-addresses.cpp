class Solution {
public:
    bool check(string s){
        if(s[0]=='0') return false;
        int v = (int)stoi(s);
        return v<=255;
    }
    void backtrackfn(string& s,int i,int partition,string as,vector<string>&ans){
        if(s.length()==i or partition==4){
            if(s.length()==i and partition==4){
                ans.push_back(as.substr(0,as.length()-1));
            }
            return;
        }
        backtrackfn(s,i+1,partition+1,as+s[i]+".",ans);
        if(i+2<=s.length() and check(s.substr(i,2)))
             backtrackfn(s,i+2,partition+1,as+s.substr(i,2)+".",ans);
        if(i+3<=s.length() and check(s.substr(i,3)))
             backtrackfn(s,i+3,partition+1,as+s.substr(i,3)+".",ans);
        cout<<partition<<endl;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrackfn(s,0,0,"",ans);
        return ans;
    }
};