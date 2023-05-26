class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0,i=0;
        for(int k=0;k<nums.size();k++){
            if(nums[k]==0) z++;
            else if(nums[k]==2) t++;
            else o++;
        }
        while(z--) nums[i++]=0;
        while(o--) nums[i++]=1;
        while(t--) nums[i++]=2;
    }
};