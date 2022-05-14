class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,pair<int,int>> m;
        for(auto i:paths)
        {
            for(int j=0;j<2;j++)
            {
                m[i[j]].first++;
                if(j==1)
                    m[i[j]].second++;
            }
        }
        for(auto i:m)
        {
            if(i.second.first==1&&i.second.second==1)
                return i.first;
        }
        return "";
    }
};