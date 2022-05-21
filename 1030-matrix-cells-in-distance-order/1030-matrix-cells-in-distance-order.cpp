class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        map< int,vector< pair <int,int> > > m;
        for(int i=0;i<rows;i++)
        {
            int temp=0;
            for(int j=0;j<cols;j++)
            {
                pair<int,int> v;
                v={i,j};
                temp=abs(rCenter-i)+abs(cCenter-j);
                m[temp].push_back(v);
            }
        }
        vector<vector<int>> ans;
        for(auto i:m)
        {
            vector<pair<int,int>> temp=i.second;
            for(int j=0;j<temp.size();j++)
            {
                vector<int> t={temp[j].first,temp[j].second};
                ans.push_back(t);
            }
        }
        return ans;
    }
};