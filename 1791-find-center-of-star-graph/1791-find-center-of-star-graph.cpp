class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> arr[100001];
        int mx=0,res=0;
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
            res=arr[i[0]].size()>arr[i[1]].size()?i[0]:i[1];
            mx=arr[res].size()>arr[mx].size()?res:mx;
        }
        return mx;
    }
};