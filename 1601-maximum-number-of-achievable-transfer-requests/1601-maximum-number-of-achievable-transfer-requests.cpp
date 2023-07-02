class Solution {
public:
    int ans = 0;
    vector<int> zeros;
    void solve(int n,int index,int count,vector<vector<int>>&requests,vector<int>&buildings){
        if(index>=requests.size()){
            if(buildings==zeros) ans=max(ans,count);
            return;
        }
        // chooseTheBuilding
        int from=requests[index][0],to=requests[index][1];
        buildings[from]--;
        buildings[to]++;
        solve(n,index+1,count+1,requests,buildings);
        // notChooseTheBuilding [Backtrack]
        buildings[from]++;
        buildings[to]--;
        solve(n,index+1,count,requests,buildings);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> b(n,0);
        zeros=b;
        solve(n,0,0,requests,b);
        return ans;
    }
};