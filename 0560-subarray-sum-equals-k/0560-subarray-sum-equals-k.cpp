class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int count = 0, sum = 0;
        for(auto i:nums){
            sum+=i;
            if(sum==k){
                count++;
            }
            if(m.find(sum-k)!=m.end())
                count+=m[sum-k];
            m[sum]++;
        }
        return count;
    }
};