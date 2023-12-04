class Solution {
public:
    bool check(string &s){
        for(int i=0;i<2;i++){
            if(s[i]!=s[i+1]) return false;
        }
        return true;
    }
    string largestGoodInteger(string num) {
        string n="",mx="";
        for(int i=0;i<3;i++){
            n+=num[i];
        }
        if(check(n))
            mx=n;
        for(int i=3;i<num.size();i++){
            n=n.substr(1)+num[i];
            if(check(n)){
                if(mx=="") mx=n;
                else if(stoi(mx)<stoi(n)) mx=n;
            }
        }
        return mx;
    }
};