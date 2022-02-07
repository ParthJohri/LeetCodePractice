class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefsum=0,mx=INT_MIN;
        vector<int> p={0};
        for(auto i: gain)
        {
            prefsum+=i;
            p.push_back(prefsum);
        }
        for(auto i:p)
            mx=max(i,mx);
        return mx;
    }
};