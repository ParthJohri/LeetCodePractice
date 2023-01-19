class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        int sum=0,ans=0;
        m[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int v=sum%k;
            if(v<0) v+=k;
            if(m.count(v)) ans+=m[v];
            m[v]++;
        }
        return ans;
    }
};