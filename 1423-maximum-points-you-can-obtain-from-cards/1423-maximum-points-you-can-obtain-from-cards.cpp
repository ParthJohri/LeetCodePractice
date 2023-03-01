class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),ans=0;
        vector<int> pr(n,0),su(n,0);
        pr[0]=cardPoints[0],su[n-1]=cardPoints[n-1];
        for(int i=1;i<n;i++){
            pr[i]=pr[i-1]+cardPoints[i];
            su[n-i-1]=su[n-i]+cardPoints[n-i-1];
        }
        ans=max(pr[k-1],su[n-k]);
        for(int i=1;i<k;i++){
            ans=max(ans,pr[i-1]+su[n-k+i]);
        }
        return ans;
    }
};