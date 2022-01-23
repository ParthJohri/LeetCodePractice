class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int> m;
        vector<int> v;
        set<int> s1;
        set<int> s2;
        set<int> s3;
        for(auto i:nums1)
           s1.insert(i);
        for(auto i:nums2)
           s2.insert(i);
        for(auto i:nums3)
           s3.insert(i);
        for(auto i:s1)
           m[i]++;
        for(auto i:s2)
           m[i]++;
        for(auto i:s3)
           m[i]++;
        for(auto i:m)
           { if(i.second>=2)
                v.push_back(i.first);}
        return v;
    }
};