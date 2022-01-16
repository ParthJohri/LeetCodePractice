class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums)
            m[i]++;
        for(auto n: m)
            {if(n.second>1)
                return n.first;}
        return -1;
        }
};