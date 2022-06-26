class Solution {
private:
    int dp[10001]={0};
    long long int mod=1e9+7;
public:
    int countHousePlacements(int n) {
       // Do Climbing stairs and Fibonacci Problem ( Same Approach )
       // https://leetcode.com/problems/climbing-stairs/
       // https://leetcode.com/problems/fibonacci-number/
       long long int ans=1;
       dp[0]=1; //Empty
       dp[1]=2; //Empty, House
       for(int i=2;i<=n;i++)
       {
           dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
       }
       ans=(dp[n]%mod*dp[n]%mod)%mod;
       return ans;
    }
};