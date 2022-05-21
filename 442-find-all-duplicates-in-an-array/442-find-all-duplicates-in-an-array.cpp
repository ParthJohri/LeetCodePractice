class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;
        for(auto i:nums)
        {
            m[i]++;
            if(m[i]>1)
                v.push_back(i);
        }
        return v;
    }
};