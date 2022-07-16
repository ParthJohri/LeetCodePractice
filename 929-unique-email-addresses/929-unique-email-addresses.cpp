class Solution {
public:
    string check(string &s){
        auto l=s.find('@');
        string newstr="";
        for(int i=0;i<l;i++){
            if(s[i]=='.')
                continue;
            else if(s[i]=='+')
                break;
            newstr+=s[i];
        }
        return newstr+s.substr(l);
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto i:emails){
            string st=check(i);
            cout<<st<<endl;
            s.insert(st);
        }
        return s.size();
    }
};