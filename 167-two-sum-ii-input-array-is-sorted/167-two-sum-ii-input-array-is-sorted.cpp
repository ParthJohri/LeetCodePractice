class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)  m[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {
            if(m[target-nums[i]]>1&&nums[i]==target-nums[i])
                v.push_back(i+1);
            else if(m[target-nums[i]]>0&&nums[i]!=target-nums[i])
                v.push_back(i+1);
            if(v.size()==2)
                return v;
        }
        return v;
    }
};