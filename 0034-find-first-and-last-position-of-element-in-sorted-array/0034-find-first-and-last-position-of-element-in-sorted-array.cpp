class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int in=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
       int en=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin()-1;
       if(in<=en) return {in,en};
       return {-1,-1};
    }
};