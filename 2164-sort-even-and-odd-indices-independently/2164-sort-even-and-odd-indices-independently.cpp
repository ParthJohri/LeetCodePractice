class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        vector<int> ans(odd.size()+even.size());
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        int x=0,y=0;
        for(int i=0;i<ans.size();i++)
        {
            if(i&1)
                ans[i]=odd[x++];
            else
                ans[i]=even[y++];
        }
        return ans;
    }
};