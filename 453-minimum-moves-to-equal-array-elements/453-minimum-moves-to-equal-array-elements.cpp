class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mn=*min_element(nums.begin(),nums.end());
       int count=0;
       for(auto i:nums){
           count+=i-mn;
       }
        return count;
    }
};