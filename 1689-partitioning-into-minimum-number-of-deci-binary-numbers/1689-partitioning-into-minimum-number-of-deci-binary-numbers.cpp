class Solution {
public:
    int minPartitions(string n) {
        int mx=INT_MIN;
        for(auto i:n)
            mx=max(mx,i-'0');
        return mx;
    }
};