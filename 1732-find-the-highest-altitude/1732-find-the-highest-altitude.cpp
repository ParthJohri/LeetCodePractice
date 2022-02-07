class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefsum=0,mx=0;
        for(auto i: gain)
        {
            prefsum+=i;
            mx=max(prefsum,mx);
        }
        return mx;
    }
};