class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m,n;
        for(auto i:t) m[i]++;
        for(auto i:s) n[i]++;
        int ans=0;
        for(auto i:n){
            if(m.count(i.first)){
                int count=i.second-m[i.first];
                ans+=count<0?0:count;
            }
            else ans+=i.second;
        }
        return ans;
    }
};