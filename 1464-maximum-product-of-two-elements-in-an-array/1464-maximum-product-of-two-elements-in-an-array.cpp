class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> p;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                p.push((nums[i]-1)*(nums[j]-1));
            }
        }
        return p.top();
    }
};