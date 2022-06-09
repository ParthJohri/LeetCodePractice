class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2,0);
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            cout<<target-nums[i]<<" "<<m[target-nums[i]]<<"\n";
            if(m[target-nums[i]]>1&&nums[i]==target-nums[i])
                v[x++]=i+1;
            else if(m[target-nums[i]]>0&&nums[i]!=target-nums[i])
                v[x++]=i+1;
            if(x==2)
                return v;
        }
        return v;
    }
};