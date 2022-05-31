class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        int mx=INT_MIN;
        for(int i=0;i<groupSizes.size();i++)
        {
            m[groupSizes[i]].push_back(i);
            mx=max(mx,groupSizes[i]);
        }
        for(auto i:m)
        {
            vector<int> v;
            vector<int> temp=i.second;
            bool flag=true;
            for(int j=0;j<temp.size();j++)
            {
                v.push_back(temp[j]);
                if(v.size()==i.first)
                {
                    flag=false;
                    ans.push_back(v);
                    v.clear();
                }
            }
            if(flag)
            ans.push_back(v);
        }
        return ans;
    }
};