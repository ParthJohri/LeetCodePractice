class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count=0;
        int maxStart=0,minStart=0,start=0;
        bool maxflag=false,minflag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK or nums[i]<minK){
                maxflag=false;
                minflag=false;
                start=i+1;
            }
            if(nums[i]==minK){
                minflag=true;
                minStart=i;
            }
            if(nums[i]==maxK){
                maxflag=true;
                maxStart=i;
            }
            if(maxflag==true and minflag==true){
                int mn=min(maxStart,minStart);
                count+=mn-start+1;
            }
        }   
        return count;
    }
};