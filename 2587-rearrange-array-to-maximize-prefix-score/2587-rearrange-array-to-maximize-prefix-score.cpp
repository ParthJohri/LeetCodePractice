class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<long long int> pr(nums.size());
        pr[0]=nums[0];
        int sum=pr[0]>0;
        for(int i=1;i<nums.size();i++){
            pr[i]=pr[i-1]+nums[i];
            if(pr[i]<=0)
            break;
            sum++;
        }
        return sum;
    }
};