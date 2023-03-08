class Solution {
public:
    void recur(string s,int n,int leftparanthesis,vector<string>&ans,int rightparanthesis){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(leftparanthesis<n) recur(s+"(",n,leftparanthesis+1,ans,rightparanthesis);
        if(rightparanthesis<leftparanthesis) recur(s+")",n,leftparanthesis,ans,rightparanthesis+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur("",n,0,ans,0);
        return ans;
    }
};