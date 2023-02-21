class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int ans=0;
        for(int i=0;i<=31;i++){
            long long int count=0,j=1<<i;
            for(auto num:nums){
                count+=(j&num);
            }
            if(count%3!=0){
                ans|=j;
            }
        }
        return ans;
    }
};