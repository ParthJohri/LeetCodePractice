class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i1,i2,start,end;
        // Time Complexity : O(log(n1)) i.e n1 - size of the smaller array
        // When the size of the first array is smaller than n2
        if(n1<=n2)
        {
            start=0,end=n1;
            while(start<=end)
            {
                i1=start+(end-start)/2;
                // Formula to calculate the value for the pointer i2
                i2=(n1+n2+1)/2-i1;
                
                int max1=(i1==0)?INT_MIN:nums1[i1-1];
                int min1=(i1==n1)?INT_MAX:nums1[i1];
                int min2=(i2==n2)?INT_MAX:nums2[i2];
                int max2=(i2==0)?INT_MIN:nums2[i2-1];
                if(max1<=min2&&max2<=min1)
                {
                    if((n1+n2)%2==0)
                        return (double)(max(max1,max2)+min(min1,min2))/2;
                    else
                        return (double)(max(max1,max2));
                }
                else if(max1>min2)
                    end=i1-1;
                else
                    start=i1+1;
            }
        }
        // When n2 is smaller, we will interchange the pointers
        else
        {
            start=0,end=n2;
            while(start<=end)
            {
                i2=start+(end-start)/2;
                // Changing the pointers in the formula mentioned
                i1=(n1+n2+1)/2-i2;
                int max1=(i1==0)?INT_MIN:nums1[i1-1];
                int min1=(i1==n1)?INT_MAX:nums1[i1];
                int min2=(i2==n2)?INT_MAX:nums2[i2];
                int max2=(i2==0)?INT_MIN:nums2[i2-1];
                if(max1<=min2&&max2<=min1)
                {
                    if((n1+n2)%2==0)
                        return (double)(max(max1,max2)+min(min1,min2))/2;
                    else
                        return (double)(max(max1,max2));
                }
                else if(max2>min1)
                    end=i2-1;
                else
                    start=i2+1;
            }
        }
    return 0.00000;
    }
};