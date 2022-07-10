class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),pr=nums[0],count=0,i=0,j=1;
        if(k<=1) return 0;
        if(pr<k) count++;
        while(j<n) {
            pr*=nums[j];
            if(pr<k)
                count+=j-i+1;
            else {
                while(pr>=k) {
                    pr/=nums[i];
                    i++;
                }
                count+=j-i+1;
            }
            j++;
        }
        return count;
    }
};