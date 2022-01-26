class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> m;
        for(auto i: nums)
            m[i]++;
        for(auto i: m)
        {
            if(i.second==1)
            sum+=i.first;
        }
        return sum;
    }
};