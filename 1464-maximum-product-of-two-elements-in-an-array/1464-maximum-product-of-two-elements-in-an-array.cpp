class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> p;
        for(auto i:nums) p.push(i);
        int lar=p.top();
        p.pop();
        int slar=p.top();
        return (lar-1)*(slar-1);
    }
};