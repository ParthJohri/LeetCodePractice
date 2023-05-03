class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2,vector<int>());
        map<int,int> m,n;
        set<int> s,t;
        for(auto i:nums1){
            m[i]++;
        }
        for(auto i:nums2){
            n[i]++;
        }
        for(auto i:nums1){
            if(!n.count(i)){
                s.insert(i);
            }
        }
        for(auto i:nums2){
            if(!m.count(i)){
                t.insert(i);
            }
        }
        for(auto i:s){
            ans[0].push_back(i);
        }
        for(auto i:t){
            ans[1].push_back(i);
        }
        return ans;
    }
};