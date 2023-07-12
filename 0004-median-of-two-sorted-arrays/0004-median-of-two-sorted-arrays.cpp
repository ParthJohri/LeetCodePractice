class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        double ans=0.0;
        int low=0,high=nums1.size();
        while(low<=high){
            
            int mid=low+(high-low)/2;
            int cut1=mid;
            int cut2=(nums1.size()+nums2.size()+1)/2-cut1;
            int l1,l2,r1,r2;
            
            l1 = cut1==0?INT_MIN:nums1[cut1-1];
            l2 = cut2==0?INT_MIN:nums2[cut2-1];
            
            r1 = cut1==nums1.size()?INT_MAX:nums1[cut1];
            r2 = cut2==nums2.size()?INT_MAX:nums2[cut2];
            
            if(l1<=r2 and l2<=r1){
                if((nums1.size()+nums2.size())%2==0)
                ans=(max(l1,l2)+min(r1,r2))/2.0;
                else ans=max(l1,l2);
                return ans;
            }
            else if(l1>r2){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};