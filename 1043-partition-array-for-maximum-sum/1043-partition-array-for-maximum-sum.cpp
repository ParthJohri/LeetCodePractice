class Solution {
public:
    int dp[501];
    int recur(vector<int>&arr,int index,int k){
        if(index>=arr.size() or k==0) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans=INT_MIN,pmx=INT_MIN,n=arr.size(),l=min(n,index+k);
        for(int i=index;i<l;i++){
            pmx=max(pmx,arr[i]);
            ans=max(ans,pmx*(i-index+1)+recur(arr,i+1,k));
        }
        dp[index]=ans;
        return dp[index];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return recur(arr,0,k);
    }
};