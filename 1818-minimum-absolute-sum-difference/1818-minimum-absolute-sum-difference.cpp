class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long int mxindex=0,temp=INT_MIN,sum=0,mod=1e9+7,ans=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            long long int v=abs(nums1[i]-nums2[i]);
            sum+=v%mod;
        }
        vector<int> nums=nums1;
        sort(nums.begin(),nums.end());
        long long int diff=INT_MIN;

        for(int i=0;i<nums1.size();i++){
            long long int val=nums2[i],temp=0,temp2=0;
            long long int v=abs(nums1[i]-nums2[i]);
            int closest=lower_bound(nums.begin(),nums.end(),val)-nums.begin();
            int closest2=upper_bound(nums.begin(),nums.end(),val)-nums.begin()-1;
            if(closest==-1) closest=0;
            if(closest==nums1.size()) closest--;
            if(closest2==-1) closest2=0;
            if(closest2==nums1.size()) closest2--;
            nums1[i]=nums[closest];
            temp=abs(nums1[i]-nums2[i])%mod;
            diff=max(diff,v-temp);
            nums1[i]=nums[closest2];
            temp=abs(nums1[i]-nums2[i])%mod;
            diff=max(diff,v-temp);
        }
        ans=(sum-diff+mod)%mod;
        return (int)ans%mod;
    }
};