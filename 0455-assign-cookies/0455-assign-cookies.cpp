class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0,id=0;
        for(int i=0;i<g.size();i++){
            int l=lower_bound(s.begin()+id,s.end(),g[i])-s.begin();
            id=l+1;
            if(l==s.size()) break;
            ans++;
        }
        return ans;
    }
};