class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0,left=0,right=0,mn=0,mx=0;
        multiset<int> s;
        while(right<nums.size()){
            s.insert(nums[right]);
            mn=*s.begin();
            mx=*s.rbegin();
            if(abs(mn-mx)>limit){
                mn=*s.begin();
                mx=*s.rbegin();
                while(!s.empty() and abs(mn-mx)>limit and left<=right){
                    s.erase(s.find(nums[left]));
                    mn=*s.begin();
                    mx=*s.rbegin();
                    left++;
                }
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};