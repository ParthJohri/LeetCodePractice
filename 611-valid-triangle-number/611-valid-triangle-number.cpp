class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=nums.size()-1;i>=2;i--)
        {
            int j=i-1,k=0;
            while(j>k)
            {
            if(nums[i]<nums[j]+nums[k]) {count+=j-k;j--;}
            else if(nums[i]>=nums[j]+nums[k]) k++;
            else j--;
            }
        // 2,3,4,6,7,7,9,38,277
        }
        return count;
    }
};