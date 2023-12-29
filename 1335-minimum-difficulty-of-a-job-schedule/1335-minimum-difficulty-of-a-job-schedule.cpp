class Solution {
public:
    long long int dp[1007][301];
    long long int recur(vector<int>&job,int i,int d){
        if(i==job.size() and d==0){
            return 0;
        }
        if(i>=job.size() or d<0) return INT_MAX;
        if(dp[i][d]!=-1) return dp[i][d];
        long long int sum=0,ans=INT_MAX;
        for(int j=i;j<job.size();j++){
            sum=max(sum,1ll*job[j]);
            int a=recur(job,j+1,d-1);
            int b=recur(job,j+1,d);
            int val=min(a,b);
            ans=min(ans,sum+val);
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        int ans = recur(jobDifficulty,0,d);
        return ans==INT_MAX?-1:ans;
    }
};