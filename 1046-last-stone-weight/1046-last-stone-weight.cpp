class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(auto i:stones) p.push(i);
        while(p.size()!=1)
        {
            int t=p.top();
            p.pop();
            int s=p.top();
            p.pop();
            p.push(abs(t-s));
        }
        return p.top();
    }
};