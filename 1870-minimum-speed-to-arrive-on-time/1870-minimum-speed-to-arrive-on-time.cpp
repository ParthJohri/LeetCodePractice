class Solution {
public:
    bool fn(vector<int>&nums,double mid,double hour){
        double sum=0;
        for(int i=0;i<nums.size()-1;i++){
            double x=nums[i];
            sum+=ceil(x/mid);
        }
        double x=nums[nums.size()-1];
        sum+=x/mid;
        return sum<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long int left=1,right=INT_MAX,ans=-1;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if(fn(dist,mid,hour)){
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