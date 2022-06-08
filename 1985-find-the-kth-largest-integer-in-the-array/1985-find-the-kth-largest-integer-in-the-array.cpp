class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int,string>> p;
        for(auto i:nums) p.push({i.length(),i});
        while(k!=1)
        {
            p.pop();
            k--;
        }
        return p.top().second;
    }
};