class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<vector<int>> v;
        for(auto i:words){
            vector<int> ch(26,0);
            string t="";
            for(auto j:i){
                if(ch[j-'a']==0)
                ch[j-'a']++;
            }
            v.push_back(ch);
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(v[i]==v[j]) ++ans;
            }
        }
        return ans;
    }
};