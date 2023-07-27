class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int ans=0,left=0,right=LONG_MAX;
        while(left<=right){
            long long int mid=left+(right-left)/2,sum=0ll;
            for(auto i:batteries){
                sum+=min((long long)i,mid);
            }
            if(sum/n>=mid){
                left=mid+1;
                ans=mid;
            }
            else right=mid-1;
        }
        return ans;
    }
};