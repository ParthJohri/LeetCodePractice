class Solution {
public:
    static bool cmp(pair<string,int> &a,pair<string,int> &b){
        if(a.first.length()==b.first.length()){
            return a.second<=b.second;
        }
        return a.first.length()<b.first.length();
    }
    string arrangeWords(string text) {
        text+=" ";
        string s="";
        int count=0;
        vector<pair<string,int>> v;
        for(auto i:text){
            if(i!=' ')
                s+=tolower(i);
            else{
                v.push_back({s,count});
                s="";
                count++;
            }
        }
       sort(v.begin(),v.end(),cmp);
       string ans="";
        for(auto i:v){
            ans+=i.first+" ";
        }
       ans[0]=toupper(ans[0]);
       return ans.substr(0,ans.length()-1);
    }
};