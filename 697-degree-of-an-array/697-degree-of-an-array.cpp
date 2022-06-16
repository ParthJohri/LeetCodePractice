class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,pair<int,int>>> m;
        int mx=INT_MIN,mn=INT_MAX;
        bool b=true;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].first++;
            if(m[nums[i]].first==1)
            {
                m[nums[i]].second.first=i;
            }
            else if(m[nums[i]].first>1)
            {
                b=false;
                mx=max(mx,m[nums[i]].first);
                m[nums[i]].second.second=i;
            }
        }
        for(auto i:m)
        {
            if(i.second.first==mx)
            {
                int temp=i.second.second.second-i.second.second.first+1;
                mn=min(mn,temp);
            }
        }
        
        return b?1:mn;
    }
};