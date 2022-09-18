class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,count=1;
        nums.push_back(-1);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0 and nums[i+1]==0){
                count++;
            }
            else if(nums[i]!=0) continue;
            else{
                ans+=(count*1ll*(count+1)/2);
                count=1;
            }
        }
        return ans;
    }
};