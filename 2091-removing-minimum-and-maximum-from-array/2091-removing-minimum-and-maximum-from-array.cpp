class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=INT_MAX,mx=INT_MIN,mnp,mxp,ans=0;
        if(nums.size()<=2) return nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mn) 
            {
                mn=nums[i];
                mnp=i;
            }
            if(nums[i]>mx) 
            {
                mx=nums[i];
                mxp=i;
            }
        }
        cout<<mx<<"\t"<<mn<<endl;
        if(mxp<=mnp)
        {
            int c=nums.size()-mnp+mxp+1;
            int d=mnp+1;
            int e=nums.size()-mxp;
            ans=min(min(c,d),e);
        }
        else if(mxp>mnp)
        {
            int c=nums.size()-mxp+mnp+1;
            int d=mxp+1;
            int e=nums.size()-mnp;
            ans=min(min(c,d),e);
        }
        return ans;
    }
};