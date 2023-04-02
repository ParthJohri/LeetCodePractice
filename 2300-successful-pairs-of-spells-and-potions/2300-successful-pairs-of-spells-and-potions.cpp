class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        long long int n=potions.size();
        for(auto i:spells){
            long long int s=(success+i-1)/i;
            long long int index=lower_bound(potions.begin(),potions.end(),s)-potions.begin();
            ans.push_back(n-index);
        }
        return ans;
    }
};