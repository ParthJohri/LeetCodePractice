class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int> m;
        for(auto i:nums)
            m[i]++;
        int count=0;
        for(auto i:m)
        {
            if(i.second>1)
                count+=(i.second)*(i.second-1)/2;
        }
        return count;
    }
};