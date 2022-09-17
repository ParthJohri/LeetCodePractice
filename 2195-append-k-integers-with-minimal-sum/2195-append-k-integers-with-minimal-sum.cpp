class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum=0;
        int n=1;
        sort(nums.begin(),nums.end());
        if(nums[0]!=1){
            int count=min(k,nums[0]-1);
            sum+=((count*1LL*(count+1))/2);
            k-=(count);
        }
        if(k<=0) return sum;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>1){
                int l=nums[i],r=nums[i+1];
                int count=min(r-l-1,k);
                if(k-count>0)
                sum+=((r*1ll*(r+1))/2)-((l*1ll*(l+1))/2)-r;
                else{
                    int x=l+k;
                sum+=((x*1ll*(x+1))/2)-((l*1ll*(l+1))/2);
                }
                k-=count;
                if(k<=0) return sum;
            }
        }
        if(k<=0) return sum;
        int r=nums[nums.size()-1]+k,l=nums[nums.size()-1];
        sum+=((r*1ll*(r+1))/2)-((l*1ll*(l+1))/2);
        return sum;
    }
};