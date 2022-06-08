class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(auto i:nums)
            p.push(i);
        while(k!=1)
        {
            p.pop();
            k--;
        }
        return p.top();
    }
};