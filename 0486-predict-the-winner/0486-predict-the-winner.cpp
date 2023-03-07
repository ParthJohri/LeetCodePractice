class Solution {
public:
    bool recur(int start,int end,int p1score,int p2score,bool p1turn,vector<int>&nums){
        if(start>end) return p1score>=p2score;
        if(p1turn) {
            int p1choicea=recur(start+1,end,p1score+nums[start],p2score,false,nums);
            int p1choiceb=recur(start,end-1,p1score+nums[end],p2score,false,nums);
            return p1choicea or p1choiceb;
        }
        else {
            int p2choicea=recur(start+1,end,p1score,p2score+nums[start],true,nums);
            int p2choiceb=recur(start,end-1,p1score,p2score+nums[end],true,nums);
            return p2choicea and p2choiceb;
        }
    }
    int minmax(int start,int end,vector<vector<int>>&dp,bool p1turn,vector<int>&nums){
        if(start>end) return -1;
        if(start==end) return nums[start];
        if(dp[start][end]!=-1) return dp[start][end];
        if(p1turn) {
            int p1choicea=nums[start]+minmax(start+1,end,dp,false,nums);
            int p1choiceb=nums[end]+minmax(start,end-1,dp,false,nums);
            return dp[start][end]=max(p1choicea,p1choiceb);
        }
        else {
            int p2choicea=-nums[start]+minmax(start+1,end,dp,true,nums);
            int p2choiceb=-nums[end]+minmax(start,end-1,dp,true,nums);
            return dp[start][end]=min(p2choicea,p2choiceb);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()==1) return true;
        vector<vector<int>> dp(25,vector<int>(25,-1));
        // return recur(0,nums.size()-1,0,0,true,nums);
        return minmax(0,nums.size()-1,dp,true,nums)>=0;
    }
};