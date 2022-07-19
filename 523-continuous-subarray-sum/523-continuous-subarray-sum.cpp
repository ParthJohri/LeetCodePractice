class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0,x=1,p=2,rem=0;
        unordered_map<int,int> m;
        m[0]=-1;
        if(nums.size()<2) return false;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(k!=0){
                rem=sum%k;
                if(rem<0) rem+=abs(k);
            }
            if(m.count(rem)){
                if(i-m[rem]>1)
                return true;
            }
            else
            m[rem]=i;
        }
        return false;
    }
};