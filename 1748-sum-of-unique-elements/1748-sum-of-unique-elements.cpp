class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum=0;
        vector<int> b(101,0);
        for(auto i:nums)
            b[i]++;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==1)
            sum+=i;
        }
        return sum;
    }
};