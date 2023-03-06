class Solution {
public:
    long long int fn(vector<int>&nums,long long int mid){
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        return sum;
    }
    long long int minimizedMaximum(int n, vector<int>& quantities) {
        long long int left=1,right=INT_MAX,ans=0;
        while(left<=right){
            long long int mid=left+(right-left)/2;
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