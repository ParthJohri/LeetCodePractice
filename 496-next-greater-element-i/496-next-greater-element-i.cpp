class Solution {
public:
    const int num=1000001;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 1. nums2 daily temp;
        // 2. num1 element search in nums2
        vector<int> nb(num,-1);
        vector<int> ans(nums1.size(),0);
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!s.empty())
            {
                if(nums2[s.top()]>nums2[i])
                {    
                    nb[nums2[i]]=nums2[s.top()]; 
                    break;
                }
                else
                    s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=nb[nums1[i]];
        }
        return ans;
    }
};