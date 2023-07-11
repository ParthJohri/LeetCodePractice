class Solution {
private: map<string,int> m;
public:
    void recur(string&s,string str,int index,vector<string>&ans){
        if(index>=s.length()){
            ans.push_back(str);
            return;
        }
        str+=" ";
        for(int i=index;i<s.length();i++){
            string temp=s.substr(index,i-index+1);
            if(m.count(temp)){
                recur(s,str+temp,i+1,ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        for(auto i:wordDict) m[i]++;
        for(int i=0;i<s.length();i++){
            string str=s.substr(0,i+1);
            if(m.count(str)){
                recur(s,str,i+1,ans);
            }
        }
        return ans;
    }
};