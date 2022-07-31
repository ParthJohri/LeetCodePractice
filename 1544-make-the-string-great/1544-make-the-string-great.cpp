class Solution {
public:
    string makeGood(string s) {
        stack<char> str;
        string ans="";
        for(auto i:s){
            if(str.empty())
                str.push(i);
            else if(tolower(i)==tolower(str.top()) && (isupper(i) && islower(str.top()) || islower(i) && isupper(str.top()))){
                str.pop();
                continue;
            }
            else
            str.push(i);
        }
        while(!str.empty()){
            ans+=str.top();
            str.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};