class Solution {
public:
    string removeStars(string s) {
        stack<char> stac;
        string ans="";
        for(auto i:s){
            if(i!='*') stac.push(i);
            else {
            if(!stac.empty())
            stac.pop();
            }
        }
        while(!stac.empty()){
            ans+=stac.top();
            stac.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};