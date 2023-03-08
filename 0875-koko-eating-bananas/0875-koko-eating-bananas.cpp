class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=INT_MAX,ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int sum=0;
            for(auto i:piles){
                sum+=(i+mid-1)/mid;
            }
            if(sum<=h){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};