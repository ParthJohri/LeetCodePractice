class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0,gp=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1,sum=nums[i];
            while(j<k){
                if(abs(sum+nums[j]+nums[k]-target)<gp){
                    gp=abs(sum+nums[j]+nums[k]-target);
                    ans=sum+nums[j]+nums[k];
                }
                if(sum+nums[j]+nums[k]<target)
                    j++;
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};