class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int i=0,j=1,n=nums.size(),pr=nums[0],count=0,len=0;
        if(k<=1) return 0;
        if(pr<k) count++;
        while(j<n) {
            len=j-i+1;
            pr+=nums[j];
            if(pr*len<k)
                count+=j-i+1;
            else {
                while(pr*len>=k) {
                    pr-=nums[i];
                    i++;
                    len--;
                }
                count+=j-i+1;
            }
            j++;
        }
        return count;
    }
};