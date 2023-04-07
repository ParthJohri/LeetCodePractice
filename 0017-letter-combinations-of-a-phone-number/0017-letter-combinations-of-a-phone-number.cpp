class Solution {
public:
    void dfs(vector<string>&ans, map<char,string>&m, string& digits,int num,string& s){
        if(num==digits.length()){
            ans.push_back(s);
        }
        for(auto i:m[digits[num]]){
            s.push_back(i);
            dfs(ans,m,digits,num+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> m={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        vector<string> ans;
        int n=0;
        string s="";
        if(digits.length()==0) return ans;
        dfs(ans,m,digits,n,s);
        return ans;
    }
};