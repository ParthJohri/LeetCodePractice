class Solution {
public:
    vector<int> distributeCandies(int c, int num) {
        vector<int> ans(num,0);
        int x=0,cn=0;
        while(c>0){
            cn=c<x+1?c:x+1;
            ans[x%num]+=cn;
            x++;
            c-=cn;
        }
        return ans;
    }
};