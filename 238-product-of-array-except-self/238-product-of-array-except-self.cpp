class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pr(n,1),sf(n,1),v(n,1);
        pr[0]=nums[0];
        for(int i=1;i<n;i++){
            pr[i]=pr[i-1]*nums[i];
        }
        sf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sf[i]=sf[i+1]*nums[i];
        }
        v[0]=sf[1];
        for(int i=1;i<n-1;i++){
            v[i]=pr[i-1]*sf[i+1];
        }
        v[n-1]=pr[n-2];
        return v;
    }
};