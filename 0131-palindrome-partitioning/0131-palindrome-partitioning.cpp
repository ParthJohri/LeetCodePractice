class Solution {
public:
    bool checkpalindrome(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string s,vector<string> temp,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.length();i++){
            string str=s.substr(0,i+1);
            if(checkpalindrome(str)){
                temp.push_back(str);
                backtrack(s.substr(i+1),temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> temp;
        backtrack(s,temp,ans);
        return ans;
    }
};