class Solution {
public:
    bool fn(vector<int>&nums,long long int mid,int totalTrips){
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=mid/nums[i];
            if(sum>=totalTrips) return true;
        }
        return sum>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int left=1,right=LONG_MAX,ans=0;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if(fn(time,mid,totalTrips)){
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