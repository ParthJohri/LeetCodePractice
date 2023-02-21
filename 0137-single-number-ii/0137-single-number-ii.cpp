class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=31;i++){
            long long int count=0,j=1<<i;
            for(auto num:nums){
                if((j&num))
                count++;
            }
            if(count%3!=0){
                ans|=j;
            }
        }
        return ans;
    }
};