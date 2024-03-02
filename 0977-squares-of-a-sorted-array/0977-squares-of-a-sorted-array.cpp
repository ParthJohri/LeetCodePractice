class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sq;
        for(auto i:nums) sq.push_back(i*i);
        sort(sq.begin(),sq.end());
        return sq;
    }
};