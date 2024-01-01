class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0,i=s.size()-1,j=g.size()-1;
        while(i>=0 and j>=0){
            if(g[j]>s[i]){
                j--;
            }
            else {
                i--;
                j--;
                ans++;
            }
        }
        return ans;
    }
};