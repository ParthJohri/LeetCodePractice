class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0,s=0;
        if(k==0){
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]!=nums2[i]) return -1;
            }
            return 0;
        }
        for(int i=0;i<nums1.size();i++){
            if(abs(nums1[i]-nums2[i])%k!=0) return -1;
            if(nums1[i]>nums2[i]){
            s+=(nums1[i]-nums2[i])/k;
            ans+=(nums1[i]-nums2[i])/k;}
            else
            ans-=(nums2[i]-nums1[i])/k;
        }
        cout<<ans<<s<<endl;
        if(ans!=0) return -1;
        return s;
    }
};