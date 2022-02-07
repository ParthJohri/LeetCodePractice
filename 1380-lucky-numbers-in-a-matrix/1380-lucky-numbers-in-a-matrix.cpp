class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> m;
        for(auto i:matrix)
        {
            int sm=*min_element(i.begin(),i.end());
            m[sm]++;
        }
        vector<vector<int> > tp;
        for(int i=0;i<matrix[0].size();i++)
            
        {
            vector<int> top;
            for(int j=0;j<matrix.size();j++)
            {
                top.push_back(matrix[j][i]);
            }
         tp.push_back(top);
         top.clear();
        }
        
        for(auto i:tp)
        {
            int lar=*max_element(i.begin(),i.end());
            m[lar]++;
        }
        vector<int> v;
        for(auto i:m)
        {
            if(i.second==2)
                v.push_back(i.first);
        }
        return v;
    }
};