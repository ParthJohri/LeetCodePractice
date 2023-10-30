class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> bit;
        vector<int> ans;
        for(int i=0;i<n;i++){
            bit.push_back({__builtin_popcountll(arr[i]),arr[i]});
        }
        sort(bit.begin(),bit.end());
        for(auto i:bit){
            ans.push_back(i[1]);
        }
        return ans;
    }
};