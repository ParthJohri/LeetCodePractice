class Solution {
public:
    void recur(string s,int leftparanthesis,vector<string>&ans,int rightparanthesis){
        if(leftparanthesis==0 and rightparanthesis==0){
            ans.push_back(s);
            return;
        }
        if(rightparanthesis>0) recur(s+")",leftparanthesis,ans,rightparanthesis-1);
        if(leftparanthesis>0) recur(s+"(",leftparanthesis-1,ans,rightparanthesis+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur("",n,ans,0);
        return ans;
    }
};