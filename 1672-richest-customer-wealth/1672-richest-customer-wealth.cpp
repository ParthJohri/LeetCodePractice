class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        for(auto i: accounts)
        {
            sum=max(sum,accumulate(i.begin(),i.end(),0));
        }
        return sum;
    }
};