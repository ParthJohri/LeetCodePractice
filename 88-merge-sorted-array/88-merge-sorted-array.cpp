class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,merge=0;
        // Merge Sort Algorithm Important
        vector<int> v=nums1;
        while(i<m&&j<n)
        {
            if(v[i]<=nums2[j])
                nums1[merge]=v[i++];
            else
                nums1[merge]=nums2[j++];
            merge++;
        }
        while(i<m)
            nums1[merge++]=v[i++];
        while(j<n)
            nums1[merge++]=nums2[j++];
    }
};