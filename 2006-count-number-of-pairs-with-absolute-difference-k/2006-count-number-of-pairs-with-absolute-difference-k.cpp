class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        vector<int>v(201,0);
        for(auto i:nums)
            v[i]++;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0&&v[i+k]!=0)
            count+=v[i]*v[i+k];
        }
        return count;
    }
};