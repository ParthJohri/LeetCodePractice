class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        int ans=0;
        for(auto i:nums) m[i]++;
        for(auto i:m){
            ans+=(i.second*(i.second-1)/2);
        }
        return ans;
    }
};