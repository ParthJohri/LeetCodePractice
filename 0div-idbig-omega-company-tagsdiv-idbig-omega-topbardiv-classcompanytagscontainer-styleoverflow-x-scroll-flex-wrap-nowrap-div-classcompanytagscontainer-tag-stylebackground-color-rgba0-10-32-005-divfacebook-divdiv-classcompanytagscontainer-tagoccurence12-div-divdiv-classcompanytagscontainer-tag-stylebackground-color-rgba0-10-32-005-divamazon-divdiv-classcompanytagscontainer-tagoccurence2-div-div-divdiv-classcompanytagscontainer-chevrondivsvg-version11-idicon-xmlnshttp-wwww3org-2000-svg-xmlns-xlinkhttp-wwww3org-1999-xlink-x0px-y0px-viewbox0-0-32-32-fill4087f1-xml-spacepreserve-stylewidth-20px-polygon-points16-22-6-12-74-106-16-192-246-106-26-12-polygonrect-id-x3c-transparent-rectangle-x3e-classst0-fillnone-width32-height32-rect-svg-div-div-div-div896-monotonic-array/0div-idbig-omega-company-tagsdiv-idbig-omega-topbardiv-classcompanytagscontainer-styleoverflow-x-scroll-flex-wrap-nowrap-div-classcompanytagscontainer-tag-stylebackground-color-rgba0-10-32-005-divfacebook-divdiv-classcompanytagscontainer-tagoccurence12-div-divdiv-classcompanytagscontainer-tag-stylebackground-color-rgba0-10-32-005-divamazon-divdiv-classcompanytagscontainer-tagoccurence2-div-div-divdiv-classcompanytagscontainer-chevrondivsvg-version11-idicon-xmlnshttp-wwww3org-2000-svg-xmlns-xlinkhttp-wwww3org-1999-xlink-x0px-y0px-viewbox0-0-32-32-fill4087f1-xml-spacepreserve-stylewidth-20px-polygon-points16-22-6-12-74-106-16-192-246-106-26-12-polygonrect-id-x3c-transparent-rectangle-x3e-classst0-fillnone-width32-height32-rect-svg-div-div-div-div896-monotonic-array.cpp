class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int count=0,dup=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) dup++;
            else if(nums[i]>nums[i+1]) ++count;
        } 
        // cout<<count<<endl;
        return count==0 or count+dup==nums.size()-1;
    }
};