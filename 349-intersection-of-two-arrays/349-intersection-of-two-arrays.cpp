class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> count(1000,0);
        vector<int> arr;
        for(int i=0;i<nums1.size();i++)
        {
            count[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(count[nums2[i]]>0)
                     {arr.push_back(nums2[i]);
                    count[nums2[i]]=0;}
        }
        return arr;
    }
};