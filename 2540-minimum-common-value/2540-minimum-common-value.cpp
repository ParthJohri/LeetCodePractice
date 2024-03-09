class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        set<int> s,s2;
        for(auto i:nums1){
            s.insert(i);
        }
        for(auto i:s){
            m[i]++;
        }
         for(auto i:nums2){
            s2.insert(i);
        }
        for(auto i:s2){
            m[i]++;
        }
        for(auto i:m){
            if(i.second==2) return i.first;
        }
        return -1;
    }
};