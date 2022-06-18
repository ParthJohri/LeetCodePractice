class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        if(nums.size()<3) return ans;
        if(nums[0]>0) return ans;
        int i=0,j=0,k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            j=i+1;
            k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                    s.insert({nums[i],nums[j++],nums[k--]});
                else if(nums[i]+nums[j]+nums[k]<0)
                    j++;
                else
                    k--;
            }
        }
       
        for(auto i:s)
            ans.push_back(i);
        return ans;
    }
};