class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      vector<int> l,e,g,ans;
        for(auto i:nums)
        {
            if(i<pivot)
                l.push_back(i);
            else if(i==pivot)
                e.push_back(i);
            else
                g.push_back(i);
        }
        for(auto i:l)
            ans.push_back(i);
        for(auto i:e)
            ans.push_back(i);
        for(auto i:g)
            ans.push_back(i);
        return ans;
    }
};