class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=*max_element(candies.begin(),candies.end());
        vector<bool> b;
        for(auto i:candies)
                b.push_back(i+extraCandies>=maxi);
        return b;
        
    }
};