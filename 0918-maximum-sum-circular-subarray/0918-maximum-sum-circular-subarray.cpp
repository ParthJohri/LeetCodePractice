class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int val1=nums[0],val2=-nums[0],sum1=nums[0],sum2=-nums[0],fsum=0,finalanswer=0;
        for(int i=1;i<nums.size();i++){
            if(sum1<0)
            sum1=0;
            sum1+=nums[i];
            val1=max(val1,sum1);
        }
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            fsum+=nums[i];
            nums[i]=-nums[i];
        }
        for(int i=1;i<nums.size();i++){
            if(sum2<0)
            sum2=0;
            sum2+=nums[i];
            val2=max(val2,sum2);
        }
        cout<<endl;
        finalanswer=max(val1,fsum+val2);
        return mx<0?mx:finalanswer;
    }
};