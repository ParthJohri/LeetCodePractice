class Solution {
public:
    vector<string> ans;
    map<string,int> m;
    void recur(int i,string str,string&s){
        if(i>=s.size()){
            ans.push_back(str);
        }
        str+=" ";
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(m.count(temp)){
                recur(j+1,str+temp,s);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict) m[i]++;
        for(int i=0;i<s.size();i++){
            string str=s.substr(0,i+1);
            if(m.count(str)){
                recur(i+1,str,s);
            }
        }
        return ans;
    }
};