class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int pr=0,ans=0;
        m[0]=1;
        // Sliding Window does not work because of negative numbers
        for(auto i:nums){
            pr+=i;
            ans+=m[pr-k];
            m[pr]++;
        }
        return ans;
    }
};