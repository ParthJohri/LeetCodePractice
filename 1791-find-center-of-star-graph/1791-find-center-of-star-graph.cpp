class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // 2nd Solution TC:O(1) SC:O(1) 
        // Read THe Description Carefully
        // A center node is a node taht connects with every other node.
        if(edges[0][0]==edges[1][0]||edges[0][0]==edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
        // 1st Solution TC:O(N) SC:O(N)
        // vector<int> arr[100001];
        // int mx=0,res=0;
        // for(auto i:edges)
        // {
        //     arr[i[0]].push_back(i[1]);
        //     arr[i[1]].push_back(i[0]);
        //     res=arr[i[0]].size()>arr[i[1]].size()?i[0]:i[1];
        //     mx=arr[res].size()>arr[mx].size()?res:mx;
        // }
        // return mx;
    }
};