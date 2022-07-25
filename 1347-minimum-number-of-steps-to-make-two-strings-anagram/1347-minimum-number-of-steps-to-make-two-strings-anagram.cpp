class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        int ans=0;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:t){
            m[i]--;
        }
        for(auto i:m){
            ans+=i.second>0?i.second:0;
        }
        return ans;
    }
};