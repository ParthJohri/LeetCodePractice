class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        map<int,int> m;
        for(auto i:nums) m[i]++;
        for(auto i:nums){
            if(!m.count(i+1) && !m.count(i-1) && m[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};