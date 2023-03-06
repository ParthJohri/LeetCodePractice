class Solution {
public:
    int fn(vector<int>&nums,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        return sum;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=1,right=100000,ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(fn(quantities,mid)<=n){
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