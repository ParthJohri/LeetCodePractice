class Solution {
public:
    int findLHS(vector<int>& nums) {
       // Method 1 Sorting + Sliding Window TC: O(NlogN) SC: O(1)
       // sort(nums.begin(),nums.end());
       // int left=0,right=0,length=0;
       // while(right<nums.size())
       // {
       //     while(nums[right]-nums[left]>1)
       //         left++;
       //     if(nums[right]-nums[left]==1)
       //         length=max(length,right-left+1);
       //     right++;
       // }
       //  return length;
       // Method 2 Map TC: O(N) SC: O(N)
       unordered_map<int,int> m;
       for(auto i:nums) m[i]++;
       int maxi=0;
       for(auto [num,freq]:m)
        {
            if(m.find(num+1)!=m.end())
                maxi=max(maxi,freq+m[num+1]);
        }
        return maxi;
    }
};