class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>p;
        set<int> s;
        for(auto i:nums) s.insert(i);
        for(auto i:s) p.push(i);
        if(p.size() < 3)
            return p.top();
        for(int i=1;i<3;++i)
            p.pop();
        return p.top();
    }
};