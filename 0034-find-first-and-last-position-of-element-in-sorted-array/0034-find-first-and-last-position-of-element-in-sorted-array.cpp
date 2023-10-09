class Solution {
public:
    int lower_bound(vector<int>&nums,int t){
        int s=0,e=nums.size()-1,ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==t){
                e=mid-1;
                ans=mid;
            }
            else if(nums[mid]>t){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int>&nums,int t){
        int s=0,e=nums.size()-1,ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==t){
                s=mid+1;
                ans=mid;
            }
            else if(nums[mid]<t){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lower_bound(nums,target);
        int b=upper_bound(nums,target);
        return {l,b};
    }
};