class Solution {
public:
    int thresholdfn(vector<int>&nums,int val){
        int sum=0;
        for(auto i:nums){
          sum+=((i+val-1)/val);  
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1,right=INT_MAX,ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(thresholdfn(nums,mid)<=threshold){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};