class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> m;
        for(auto i: matrix)
        {vector<int> rows=i;
            for(auto j:i)
            m.push_back(j);
        }
        sort(m.begin(),m.end());
        return m[k-1];
    }
};