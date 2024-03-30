class Solution {
public:
    int slidingW(vector<int>&nums,int k){
        map<int,int> m;
        int i=0,j=0,ans=0,n=nums.size(),count=0;
        while(j<n){
            if(m[nums[j]]==0) ++count;
            m[nums[j]]++;
            while(count>k){
                if(!--m[nums[i]]){
                    count--;
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=slidingW(nums,k)-slidingW(nums,k-1);
        return ans;
    }
};