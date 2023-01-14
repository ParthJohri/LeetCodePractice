class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        vector<int> ans;
        for(auto i:arr1){
            m[i]++;
        }
        for(auto i:arr2){
            while(m[i]-->0){
                ans.push_back(i);
            }
        }
        for(auto i:m){
            while(i.second-->0) ans.push_back(i.first);
        }
        return ans;
    }
};