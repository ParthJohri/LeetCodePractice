class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=1,mn=1,tmp=0,result=*max_element(nums.begin(),nums.end());
        for(auto i:nums) {
            if(i==0) {
                mx=mn=1;
                continue;
            }
            tmp=i*mx;
            mx=max(i,max(i*mx,i*mn));
            mn=min(i,min(tmp,i*mn));
            result=max(result,mx);
        }
        return result;
    }
};