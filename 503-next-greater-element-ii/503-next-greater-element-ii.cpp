class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> v(nums.size(),-1);
        int t=nums.size();
        for(int i=0;i<t-1;i++)
        {
            nums.push_back(nums[i]);
        }
        int x=t-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            x--;
            while(!s.empty())
            {
                if(s.top()>nums[i])
                {
                    if(x<0)
                    v[i]=s.top(); 
                    break;
                }
                else
                    s.pop();
            }
            s.push(nums[i]);
        }
        return v;
    }
};