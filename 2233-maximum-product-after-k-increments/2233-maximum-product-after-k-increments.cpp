class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> p(nums.begin(),nums.end());
        const int mod=pow(10,9)+7;
        while(k--)
        {
            int newvalue=p.top()+1;
            p.pop();
            p.push(newvalue);
        }
        long long int ans=1;
        while(!p.empty())
            {
                 int t=p.top();
                 ans=(ans*t)%mod;
                 p.pop();
            }
        return ans;
    }
};