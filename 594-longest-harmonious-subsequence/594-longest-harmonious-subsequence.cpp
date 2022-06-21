class Solution {
public:
    int findLHS(vector<int>& nums) {
       unordered_map<int,int> m;
       for(auto i:nums) m[i]++;
       int maxi=0;
       for(auto [num,freq]:m)
        {
            if(m.find(num+1)!=m.end())
                maxi=max(maxi,freq+m[num+1]);
        }
        return maxi;
    }
};