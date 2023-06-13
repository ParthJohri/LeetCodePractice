class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int lis[nums.size()],count[nums.size()];
        lis[0]=1;
        count[0]=1;
        for(int i=1;i<nums.size();i++){
            lis[i]=1;
            count[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[i]==lis[j]+1)
                        count[i]+=count[j];
                    else if(lis[i]<lis[j]+1){
                        count[i]=count[j];
                        lis[i]=max(lis[i],lis[j]+1);
                    }       
                }
            }
        }
        int maxlength=1,maxlengthCount=0;
        for(auto i:lis){
            maxlength=max(maxlength,i);
        }
        for(int i=0;i<nums.size();i++){
            if(lis[i]==maxlength) maxlengthCount+=count[i];
        }
        return maxlengthCount;
    }
};