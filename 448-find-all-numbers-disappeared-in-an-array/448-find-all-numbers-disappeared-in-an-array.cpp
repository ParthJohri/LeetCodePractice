class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]>0)
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            v.push_back(i+1);
        }
        // Use the input array as hashmap and its indexes +1 as value missing
        // -4 -3 -2 -7 8 2 -3 -1
        // 0 1 2 3 4 5 6 7
        // Same concept problem
        // https://leetcode.com/problems/find-all-duplicates-in-an-array/
        // Read Discuss Section 
        // https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c%2B%2B-Four-Solution-or-O-(N*N)-to-greater-O(N)-or-Explain-All
        return v;
    }
};